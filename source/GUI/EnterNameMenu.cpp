#include "PlatformPrecomp.h"
#include "EnterNameMenu.h"
#include "Entity/EntityUtils.h"
#include "AboutMenu.h"
#include "MainMenu.h"



string tankIDname = "";
string tankIDpass = "";

string HighScoreNameFilter(string s)
{
	string temp;

	for (unsigned int i=0; i < s.length(); i++)
	{
		if ( 
			(s[i] >= 65 && s[i] <= 90)
			|| (s[i] >= 97 && s[i] <= 122)
			)
		{
			temp += s[i];		
		}
	}

	return temp;
}

void EnterNameMenuOnSelect(VariantList *pVList) //0=vec2 point of click, 1=entity sent from
{
	Entity *pEntClicked = pVList->m_variant[1].GetEntity();

	//LogMsg("Clicked %s entity at %s", pEntClicked->GetName().c_str(),pVList->m_variant[0].Print().c_str());

	if (pEntClicked->GetName() == "check_question")
	{
		bool bChecked = pEntClicked->GetVar("checked")->GetUINT32()!=0;
		if (bChecked)
		{
			GetEntityRoot()->GetEntityByName("guestname_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(1));
			GetEntityRoot()->GetEntityByName("name_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(0));
			GetEntityRoot()->GetEntityByName("pass_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(0));
		} else
		{
			GetEntityRoot()->GetEntityByName("guestname_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(0));
			GetEntityRoot()->GetEntityByName("name_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(1));
			GetEntityRoot()->GetEntityByName("pass_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(1));
		}

		//either way, save it to our db which will get saved when the app closes.
		GetApp()->GetVar("like_checkboxes")->Set(uint32(bChecked));

	}

	if (pEntClicked->GetName() == "Connect")
	{
		string name = GetEntityRoot()->GetEntityByName("name_input_box")->GetComponentByName("InputTextRender")->GetVar("text")->GetString();
		string name3 = GetEntityRoot()->GetEntityByName("guestname_input_box")->GetComponentByName("InputTextRender")->GetVar("text")->GetString();
		string name6 = GetEntityRoot()->GetEntityByName("pass_input_box")->GetComponentByName("InputTextRender")->GetVar("text")->GetString();
		GetApp()->GetVar("name")->Set(name); //save it to our database so we can remember the default
		GetApp()->GetVar("pass")->Set(name6); //save it to our database so we can remember the default
		GetApp()->GetVar("guestname")->Set(name3); //save it to our database so we can remember the default
		tankIDname = name;
		tankIDpass = name6;
		//LogMsg("Read %s for the name", GetApp()->GetVar("name")->GetString().c_str());
		SlideScreen(pEntClicked->GetParent(), false);
		GetMessageManager()->CallEntityFunction(pEntClicked->GetParent(), 500, "OnDelete", NULL);
		AboutMenuCreate(pEntClicked->GetParent()->GetParent());
	}

	if (pEntClicked->GetName() == "Back")
	{
		DisableAllButtonsEntity(pEntClicked->GetParent());
		SlideScreen(pEntClicked->GetParent(), false);
		GetMessageManager()->CallEntityFunction(pEntClicked->GetParent(), 500, "OnDelete", NULL);
		MainMenuCreate(pEntClicked->GetParent()->GetParent());
		return;
	}
	
}

Entity * EnterNameMenuCreate(Entity *pParentEnt)
{
	Entity* pBG = CreateOverlayEntity(pParentEnt, "EnterNameMenu", "ui/large/generic_menu.rttex", 0, 0);
	pBG->GetVar("scale2d")->Set(CL_Vec2f(0.47, 0.47));
	AddFocusIfNeeded(pBG);

	Entity* pButtonEntity;
	CL_Vec2f vTextAreaPos = CL_Vec2f(240,10);
	CL_Vec2f vTextAreaBounds = CL_Vec2f(384,170);
	CL_Vec2f vTextAreaPos2 = CL_Vec2f(20, 35);
	CL_Vec2f vTextAreaBounds2 = CL_Vec2f(384, 170);
	
	pButtonEntity = CreateTextLabelEntity(pBG, "guestname", vTextAreaPos2.x, vTextAreaPos2.y, "Name: ");
	//pButtonEntity->GetVar("scale2d")->Set(CL_Vec2f(0.5f, 0.5f));
	//pButtonEntity->GetComponentByName("TextRender")->GetVar("font")->Set(uint32(FONT_LARGE));
	float nameWidth3 = pButtonEntity->GetVar("size2d")->GetVector2().x;

	//create input box
	pButtonEntity = CreateInputTextEntity(pBG, "guestname_input_box", vTextAreaPos2.x + nameWidth3, vTextAreaPos2.y, GetApp()->GetShared()->GetVarWithDefault("guestname", string("SolidWatch"))->GetString());
	//pButtonEntity->GetVar("scale2d")->Set(CL_Vec2f(0.5f, 0.5f));
	pButtonEntity->GetVar("size2d")->Set(CL_Vec2f(130, 22));

	EntityComponent* pTextRenderComp3 = pButtonEntity->GetComponentByName("InputTextRender");

	//To allow spaces and punctuation, we active loose filtering. Use FILTERING_STRICT instead for say, a highscore name
	pTextRenderComp3->GetVar("filtering")->Set(uint32(InputTextRenderComponent::FILTERING_LOOSE));

	//you also need to do this for loose filtering to make sure the best keyboard is chosen on the device
	pTextRenderComp3->GetVar("inputType")->Set(uint32(InputTextRenderComponent::INPUT_TYPE_ASCII_FULL));

	//control how many characters the user can enter
	pTextRenderComp3->GetVar("inputLengthMax")->Set(uint32(18));

	//string title = "`$Input some stuff!";
	//pButtonEntity = CreateTextLabelEntity(pBG, "title", vTextAreaPos.x, vTextAreaPos.y, title);
	//pButtonEntity->GetComponentByName("TextRender")->GetVar("font")->Set(uint32(FONT_LARGE));
	//pButtonEntity->GetVar("scale2d")->Set(CL_Vec2f(0.6f, 0.6f));
	vTextAreaPos.y += 25;
	
	//string msg = "`wEnter your name, then click Connect to go online!";
	//Entity* pText = CreateTextBoxEntity(pBG, "text", vTextAreaPos, vTextAreaBounds, msg);
	//pText->GetVar("font")->Set(uint32(FONT_GT));
	
	bool bLikeCheckboxes = GetApp()->GetVar("like_checkboxes")->GetUINT32() != 0;
	Entity* pCheckbox = CreateCheckbox(pBG, "check_question", "I have a `$GrowID", vTextAreaPos.x, vTextAreaPos.y, bLikeCheckboxes);
	pCheckbox->GetFunction("OnButtonSelected")->sig_function.connect(&EnterNameMenuOnSelect);

	float nameEntryY = vTextAreaPos.y + pCheckbox->GetVar("size2d")->GetVector2().y; //get the exact size that the
	//final word wrapped text actually took.
	nameEntryY += 10; //add some spacer too

	pButtonEntity = CreateTextLabelEntity(pBG, "name", vTextAreaPos.x, nameEntryY, "GrowID: ");
	//pButtonEntity->GetVar("scale2d")->Set(CL_Vec2f(0.5f, 0.5f));
	//pButtonEntity->GetComponentByName("TextRender")->GetVar("font")->Set(uint32(FONT_LARGE));
	float nameWidth = pButtonEntity->GetVar("size2d")->GetVector2().x;

	//create input box
	pButtonEntity = CreateInputTextEntity(pBG, "name_input_box", vTextAreaPos.x+nameWidth, nameEntryY, GetApp()->GetShared()->GetVarWithDefault("name", string(""))->GetString());
	//pButtonEntity->GetVar("scale2d")->Set(CL_Vec2f(0.5f, 0.5f));
	pButtonEntity->GetVar("size2d")->Set(CL_Vec2f(130, 22));

	EntityComponent *pTextRenderComp = pButtonEntity->GetComponentByName("InputTextRender");

	//To allow spaces and punctuation, we active loose filtering. Use FILTERING_STRICT instead for say, a highscore name
	pTextRenderComp->GetVar("filtering")->Set(uint32(InputTextRenderComponent::FILTERING_LOOSE));

	//you also need to do this for loose filtering to make sure the best keyboard is chosen on the device
	pTextRenderComp->GetVar("inputType")->Set(uint32(InputTextRenderComponent::INPUT_TYPE_ASCII_FULL));

	//control how many characters the user can enter
	pTextRenderComp->GetVar("inputLengthMax")->Set(uint32(18));

	nameEntryY += 35; //add some spacer too
	pButtonEntity = CreateTextLabelEntity(pBG, "pass", vTextAreaPos.x, nameEntryY, "Password: ");
	//pButtonEntity->GetVar("scale2d")->Set(CL_Vec2f(0.5f, 0.5f));
	//pButtonEntity->GetComponentByName("TextRender")->GetVar("font")->Set(uint32(FONT_LARGE));
	float nameWidth2 = pButtonEntity->GetVar("size2d")->GetVector2().x;

	//create input box
	pButtonEntity = CreateInputTextEntity(pBG, "pass_input_box", vTextAreaPos.x + nameWidth2, nameEntryY, GetApp()->GetShared()->GetVarWithDefault("pass", string(""))->GetString());
	//pButtonEntity->GetVar("scale2d")->Set(CL_Vec2f(0.5f, 0.5f));
	pButtonEntity->GetVar("size2d")->Set(CL_Vec2f(130, 22));

	EntityComponent* pTextRenderComp2 = pButtonEntity->GetComponentByName("InputTextRender");

	//To allow spaces and punctuation, we active loose filtering. Use FILTERING_STRICT instead for say, a highscore name
	pTextRenderComp2->GetVar("filtering")->Set(uint32(InputTextRenderComponent::FILTERING_LOOSE));

	//you also need to do this for loose filtering to make sure the best keyboard is chosen on the device
	pTextRenderComp2->GetVar("inputType")->Set(uint32(InputTextRenderComponent::INPUT_TYPE_ASCII_FULL));

	//control how many characters the user can enter
	pTextRenderComp2->GetVar("inputLengthMax")->Set(uint32(18));

	string title = "`wEnter your name, then click Connect to go online.";
	pButtonEntity = CreateTextLabelEntity(pBG, "title", vTextAreaPos2.x, vTextAreaPos2.y + 120, title);

	string title3 = "`wAn optional `$GrowID `wlets you play on multiple\ndevices without losing your stuff. To get one,\n`$Connect `wwithout one, then choose the `$Get GrowID\n`woption from the pause menu. It's free!";
	pButtonEntity = CreateTextLabelEntity(pBG, "title", vTextAreaPos2.x, vTextAreaPos2.y + 160, title3);

	//show *'s, password mode
	//pTextRenderComp->GetVar("visualStyle")->Set((uint32)InputTextRenderComponent::STYLE_PASSWORD);


	//if you wanted text to appear until it's activated:
	//pTextRenderComp->GetVar("placeHolderText")->Set("Tap here to enter your name");

	//to change the font of the text in the input box

	//the connect button

	if (!bLikeCheckboxes)
	{

		GetEntityRoot()->GetEntityByName("guestname_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(0));
		GetEntityRoot()->GetEntityByName("name_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(1));
		GetEntityRoot()->GetEntityByName("pass_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(1));

	}
	else
	{
		GetEntityRoot()->GetEntityByName("guestname_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(1));
		GetEntityRoot()->GetEntityByName("name_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(0));
		GetEntityRoot()->GetEntityByName("pass_input_box")->GetComponentByName("InputTextRender")->GetVar("disabled")->Set(uint32(0));
	}

	pButtonEntity = CreateTextButtonEntity(pBG, "Connect", vTextAreaPos2.x + 320, GetScreenSizeYf() - 30, "Connect", false);
	pButtonEntity->GetShared()->GetFunction("OnButtonSelected")->sig_function.connect(&EnterNameMenuOnSelect);
	Entity* pEnt = CreateTextButtonEntity(pBG, "Back", vTextAreaPos2.x, GetScreenSizeYf() - 30, "Back", false);
	pEnt->GetFunction("OnButtonSelected")->sig_function.connect(&EnterNameMenuOnSelect);
	SetupTextEntity(pEnt, FONT_SMALL);
	AddHotKeyToButton(pEnt, VIRTUAL_KEY_BACK);

	SlideScreen(pBG, true);
	return pBG;
}


