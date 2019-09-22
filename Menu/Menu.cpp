#include "Menu.h"
#include "TGFCfg.h"
#include "..\SDK\Vector.h"
#include "..\SDK\ISurface.h"
#include "..\Utils\Color.h"
#include "..\Utils\GlobalVars.h"
#include "..\Hooks.h"
#include "../SDK/CHudChat.h"
#include "../gui/zgui.h"

Menu g_Menu;

void Menu::Render()
{
	zgui::poll_input("Valve001");

	if (zgui::begin_window(("CashHack"), { 970, 500 }, g::Verdana, zgui::zgui_window_flags_none))
	{
		if (zgui::tab_button((" Chicken Bot"), { 69, 45 }, Tabs.legitbot))
		{
			Tabs.legitbot = true;
			Tabs.ragebot = false;
			Tabs.misc = false;
			Tabs.visual = false;
			Tabs.config = false;
			Tabs.exploits = false;
			Tabs.debug = false;
		}
				
		zgui::next_column(0, 68);

		if (zgui::tab_button(("Rage Bot"), { 69, 45 }, Tabs.ragebot))
		{
			Tabs.legitbot = false;
			Tabs.ragebot = true;
			Tabs.misc = false;
			Tabs.visual = false;
			Tabs.config = false;
			Tabs.exploits = false;
			Tabs.debug = false;
		}

		zgui::next_column(0, 136);

		if (zgui::tab_button(("Visuals"), { 69, 45 }, Tabs.visual))
		{
			Tabs.legitbot = false;
			Tabs.ragebot = false;
			Tabs.misc = false;
			Tabs.visual = true;
			Tabs.config = false;
			Tabs.exploits = false;
			Tabs.debug = false;
		}

		zgui::next_column(0, 204);

		if (zgui::tab_button(("Misc"), { 69, 45 }, Tabs.misc))
		{
			Tabs.legitbot = false;
			Tabs.ragebot = false;
			Tabs.misc = true;
			Tabs.visual = false;
			Tabs.config = false;
			Tabs.exploits = false;
			Tabs.debug = false;
		}
	

		zgui::next_column(0, 272);

		if (zgui::tab_button(("Exploits "), { 69, 45 }, Tabs.exploits))
		{
			Tabs.legitbot = false;
			Tabs.ragebot = false;
			Tabs.misc = false;
			Tabs.visual = false;
			Tabs.config = false;
			Tabs.exploits = true;
			Tabs.debug = false;
		}

		zgui::next_column(0, 340);

		if (zgui::tab_button(("Config"), { 69, 45 }, Tabs.config))
		{
			Tabs.legitbot = false;
			Tabs.ragebot = false;
			Tabs.misc = false;
			Tabs.visual = false;
			Tabs.config = true;
			Tabs.exploits = false;
			Tabs.debug = false;
		}

		zgui::next_column(0, 408);

		if (zgui::tab_button(("Update Log"), {69, 45}, Tabs.debug))
		{
			Tabs.legitbot = false;
			Tabs.ragebot = false;
			Tabs.misc = false;
			Tabs.visual = false;
			Tabs.config = false;
			Tabs.exploits = false;
			Tabs.debug = true;
		}

		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x44))
		{
			Tabs.legitbot = false;
			Tabs.ragebot = false;
			Tabs.visual = false;
			Tabs.misc = false;
			Tabs.config = false;
			Tabs.exploits = false;
			Tabs.debug = true;
		}


		if (Tabs.legitbot)
			legittab();

		if (Tabs.ragebot)
			ragetab();

		if (Tabs.visual)
			vistab();

		if (Tabs.misc)
			misctab();

		if (Tabs.config)
			cfgtab();

		if (Tabs.exploits)
			exploitstab();

		if (Tabs.debug)
			debugtab();

		zgui::end_window();
	}


}

void  Menu::legittab()
{
	
	zgui::next_column(100, 10);

	zgui::begin_groupbox(("Legit Bot"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::checkbox(("Enable"), Config.Legitbot);
		if (Config.Legitbot)
		{
			Config.Aimbot = false;
		}
		zgui::checkbox(("Aimbot"), Config.LegitAimbot);
		if (Config.LegitAimbot) {
			zgui::slider_int(("Aim FOV"), 0, 30, Config.LegitFOV);
			zgui::slider_int(("Aim Smooth"), 0, 100, Config.LegitSmooth);
			zgui::checkbox(("RCS"), Config.AimRCS);
			if (Config.AimRCS)
				zgui::slider_int(("RCS Amount"), 0, 100, Config.RCSamount);
		}
		zgui::checkbox(("Backtrack"), Config.LegitBacktrack);
		zgui::end_groupbox();
	}
	zgui::same_line();
	zgui::next_column(200, 10);
	zgui::begin_groupbox(("Individual"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		if (!Config.LegitAimbot) {
			zgui::checkbox(("Standalone RCS"), Config.StandaloneRCS);
			Config.RCSamount = 0;
			if (Config.StandaloneRCS)
				zgui::slider_int(("Amount"), 0, 100, Config.StandaloneRCSSlider);
		}
		zgui::checkbox(("Legit AA"), Config.LegitAA);
		zgui::checkbox(("Static"), Config.LegitAAStatic);
		zgui::slider_int(("Additive"), 0, 90, Config.additive);

		if (Config.LegitAA)
			Config.Antiaim = false;
		zgui::end_groupbox();
	}
}

void  Menu::ragetab()
{
	zgui::next_column(100, 10);

	zgui::begin_groupbox(("Rage Aimbot"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{

		zgui::checkbox(("Enable"), Config.Aimbot);
		if (Config.Aimbot)
		{
			Config.Legitbot = false;
		}
		zgui::checkbox(("Multipoint"), Config.MultiPoint);
		if (Config.MultiPoint)
		{
			zgui::slider_int(("Head Scale"), 0, 100, Config.HeadScale);
			zgui::slider_int(("Body Scale"), 0, 100, Config.BodyScale);
		}
		zgui::multi_combobox(("Hitboxes"), std::vector< zgui::multi_select_item >{ { "Head", & Config.Head }, { "Chest", &Config.Chest }, { "Stomach", &Config.Pelvis }, { "Arms", &Config.Arms }, { "Legs", &Config.Legs }});
		zgui::slider_int(("Min Damage"), 0, 100, Config.Mindmg);
		zgui::checkbox(("Auto Stop"), Config.Autostop);
		zgui::checkbox(("Auto Scope"), Config.Autoscope);
		zgui::slider_int(("Hitchance"), 0, 100, Config.HitchanceValue);
		zgui::checkbox(("Resolver"), Config.Resolver);
		if (Config.Resolver) {
			zgui::combobox(("Resolver type"), { ("Default") }, Config.ResolverType);
		zgui::checkbox(("Feet Fix"), Config.FixFeet);
		}
		zgui::end_groupbox();
	}
	zgui::same_line();
	zgui::next_column(200, 10);

	zgui::begin_groupbox(("Body Aim"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{		
		zgui::multi_combobox(("Baim Options"), std::vector< zgui::multi_select_item >{ { "Lethal", & Config.BaimLethal }, { "In Air", &Config.BaimInAir }, { "Always", &Config.BaimAlways }});
		if (Config.BaimLethal)
		{
			zgui::slider_int(("Health"), 0, 100, Config.BaimLethalSlider);
		}
		zgui::checkbox(("Baim After"), Config.BaimAfterEnable);
		if (Config.BaimAfterEnable)
		{
			zgui::slider_int(("X Missed Shots"), 0, 10, Config.BaimSlider);
		}
		zgui::checkbox(("Slow Walk Body Aim"), Config.SlowWalkBaim);
		zgui::key_bind(("Force Baim Key"), Config.BaimKey);
		zgui::multi_combobox(("Backtrack Options"), std::vector< zgui::multi_select_item >{ { "Shot", & Config.ShotBacktrack }, { "Position", &Config.PosBacktrack }});
		zgui::checkbox(("Delay Shot"), Config.DelayShot);
		zgui::checkbox(("Ignore Legs When Moving"), Config.IgnoreLimbs);
		zgui::checkbox(("Fake Lag Prediction"), Config.PredictFakeLag);
		zgui::end_groupbox();
	}

	zgui::same_line();
	zgui::next_column(200, 10);

	zgui::begin_groupbox(("Anti-Aim"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::checkbox(("Enable "), Config.Antiaim);
		if (Config.Antiaim)
			Config.LegitAA = false;
		zgui::combobox(("Pitch"), {("Off"), ("Down"), ("Up"), ("Fake Down"), ("Fake Up"), ("Fake Zero") }, Config.Pitch);
		zgui::slider_int(("Yaw Add"), 0, 360, Config.Yaw);
		zgui::checkbox(("At Targets"), Config.AtTarget);
		zgui::combobox(("Jitter"), { "Off", ("Random"), ("Switch"), ("Offset") }, Config.Jitter);
		zgui::slider_int(("jitter range"), 0, 180, Config.JitterRange);
		zgui::combobox(("Freestanding"), { "Off", ("Normal"), ("Desync") }, Config.FreestandType);
		if (Config.FreestandType == 0 || Config.FreestandType == 1) {
			zgui::combobox(("Desync"), { ("Off"), ("Still"), ("Stretch"), ("Jitter"), ("Meme"), ("P2C Destroyer"), ("2018 Servers") }, Config.DesyncType);
		}
		zgui::checkbox(("Static Desync"), Config.StaticDesync);
		zgui::checkbox(("On-Shot AA"), Config.OnShotAA);

		zgui::end_groupbox();
	}

	zgui::same_line();
	zgui::next_column(200, 10);

	zgui::begin_groupbox(("Anti-Aim Misc"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::slider_int(("Base Delta"), 0, 360, Config.LBYDelta);
		if (Config.FreestandType != 2 || Config.DesyncType != 5)
			zgui::key_bind(("Desync Inverter Key"), Config.DesyncInvertKey);
		zgui::end_groupbox();
	}




}

void  Menu::vistab()
{
	zgui::next_column(100, 10);


	zgui::begin_groupbox(("Player ESP"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::checkbox(("Enable#1"), Config.Esp);
		zgui::checkbox(("2D Box"), Config.Box);
		zgui::colorpicker(("Box Color"), Config.BoxColor);
		zgui::checkbox(("Draw Name"), Config.Name);
		zgui::colorpicker(("Font Color"), Config.FontColor);
		zgui::checkbox(("Draw Weapons"), Config.Weapon);
		zgui::colorpicker(("Weapon Color"), Config.WepColor);
		zgui::checkbox(("Health Bar"), Config.HealthBar);
		zgui::checkbox(("Glow"), Config.Glow);
		zgui::colorpicker(("Glow Color"), Config.GlowColor);
		zgui::multi_combobox(("Skeleton"), std::vector< zgui::multi_select_item >{ { "Normal", & Config.Skeleton[0] }, { "Backtrack", &Config.Skeleton[1] }});
		zgui::colorpicker(("Skeleton Color"), Config.SkeletonColor);
		zgui::checkbox(("Player Chams"), Config.Chams);
		zgui::colorpicker(("Chams Color"), Config.XQZ);
		zgui::checkbox(("XQZ Chams"), Config.ChamsXQZ);
		zgui::colorpicker(("XQZ Cham Color"), Config.ChamsColor);
		zgui::checkbox(("Weapon Chams"), Config.WeaponChams);
		zgui::colorpicker(("Weapon Cham Color"), Config.WeaponChamsColor);
		zgui::checkbox(("Backtrack Chams"), Config.Backtrackchams);
		zgui::colorpicker(("Backtrack Cham Color"), Config.BacktrackchamsColor);
		zgui::checkbox(("Local Chams"), Config.LocalChams);
		zgui::colorpicker(("Local Chams Color"), Config.LocalChamsColor);
		zgui::checkbox(("Pulse Chams"), Config.desyncChams);
		zgui::checkbox(("Hand Chams"), Config.HandChams);
		zgui::colorpicker(("Hand Chams Color"), Config.HandChamsColor);
		zgui::checkbox(("Fake Lag Model"), Config.FakeLagModel);
		zgui::colorpicker(("Fake Lag Model Color"), Config.FakeLagModelColor);
		zgui::checkbox(("Flags"), Config.Flags);
		zgui::end_groupbox();
	}
	
	zgui::same_line();
	zgui::next_column(200, 10);

	zgui::begin_groupbox(("World ESP"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::slider_int(("Nightmode Value"), 0, 100, Config.NightModeSlider);
		zgui::slider_int(("Asus Props"), 0, 100, Config.AsusProps);
		zgui::text(("Skybox Color"));
		zgui::colorpicker(("Skybox Color"), Config.SkyboxColor);
		zgui::checkbox(("World Modulation"), Config.NightMode);
		zgui::checkbox(("Bomb ESP"), Config.BombEsp);
		zgui::checkbox(("Projectile ESP"), Config.Projectiles);
		zgui::checkbox(("Dropped Weapon ESP"), Config.DroppedWeapons);
		zgui::checkbox(("Show Enemies On Radar"), Config.EngineRadar);
		zgui::checkbox(("Show Aimspot"), Config.ShowAimSpot);
		zgui::multi_combobox(("Removals"), std::vector< zgui::multi_select_item >{ { "Zoom", & Config.NoZoom }, { "Scope", &Config.NoScope }, { "Smoke", &Config.NoSmoke },{ "Visual Recoil", &Config.NoRecoil },{ "Post Processing", &Config.PostProcess } });

		zgui::end_groupbox();
	}

	zgui::same_line();
	zgui::next_column(200, 10);

	zgui::begin_groupbox(("Others"), { 210 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::checkbox(("Out Of View"), Config.OutOfView);
		if (Config.OutOfView)
		{
			zgui::colorpicker(("Out Of View Color"), Config.OutOfViewColor);
			zgui::slider_int(("Radius"), 0, 300, Config.OutOfViewRadius);
			zgui::slider_int(("Size"), 0, 18, Config.OutOfViewSize);
		}
		zgui::checkbox(("Anti-Aim Arrows"), Config.Arrows);
		zgui::checkbox(("Anti-Aim Monitor"), Config.AntiaimMonitor);
		zgui::checkbox(("Show Impacts"), Config.Impacts);
		zgui::checkbox(("Watermark"), Config.Watermark);
		zgui::checkbox(("Draw Hitboxes"), Config.DrawHitboxes);
		zgui::colorpicker(("Hitbox Color"), Config.ImpactColor);
		if (Config.DrawHitboxes)
		{
			zgui::slider_int(("Time"), 0, 10, Config.DrawHitboxTime);
		}
		zgui::combobox(("Show Weapon Spread"), { "Off", "Square", "Circle", "Filled Circle", "Fading Dots", "Filled Dots" }, Config.SpreadCrosshair);
		if (g_Menu.Config.SpreadCrosshair != 1)
			zgui::colorpicker(("Spread Color"), Config.SpreadColor);
		zgui::multi_combobox(("Crosshair"), std::vector< zgui::multi_select_item >{ { "Override", & Config.Crosshair[0] }, { "Penetration", &Config.Crosshair[1] }, { "Recoil", &Config.Crosshair[2] }, });
		zgui::end_groupbox();
	}

	zgui::same_line();
	zgui::next_column(210, 10);

	zgui::begin_groupbox(("Misc ESP"), { 200, 400 }, zgui::zgui_window_flags_none);
	{
		zgui::combobox(("Cham Materials"), { "Metallic", "Flat", "Crystal Blue", "Pulse", "Gold" }, Config.ChamsMaterial);

		zgui::combobox(("Hand Chams Material"), { "Metallic", "Flat", "Crystal Blue", "Pulse", "Gold", "Gloss", "Crystal", "Glass" }, Config.HandChamsMaterial);
		zgui::combobox(("Weapon Chams Material"), { "Metallic", "Flat", "Crystal Blue", "Pulse", "Gold", "Gloss", "Crystal", "Glass" }, Config.WeaponChamsMaterial);
		zgui::combobox(("Shadow Material"), { "pulse", "gloss", "crystal clear", "glass", "chrome", "lightray" }, Config.ShadowMaterial);
		zgui::checkbox(("Visual Hitmarker"), Config.VisHitmarker);
		zgui::colorpicker(("Hitmarker Color"), Config.HitmarkerColor);
		if (Config.VisHitmarker)
		{
			zgui::slider_float(("Expire Time"), 0, 4, Config.ExpireTime);
			zgui::slider_float(("Line Size"), 0, 16, Config.MarkerSize);
			zgui::checkbox(("Show Damage"), Config.VisHitDmg);
		}
		zgui::checkbox(("Desync Invert Indicator"), Config.AAInvertIndicators);
		zgui::checkbox(("Local Latency Indicator"), Config.IndicatorLatency);

		zgui::end_groupbox();
	}
}

void  Menu::misctab()
{
	zgui::next_column(100, 10);


	zgui::begin_groupbox(("Misc Settings"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::slider_int(("View FOV"), 0, 150, Config.Fov);
		zgui::checkbox(("Auto Jump"), Config.Bhop);
		zgui::checkbox(("Auto Strafe"), Config.AutoStrafe);
		zgui::checkbox(("Infinite Crouch"), Config.infinite_duck);
		zgui::combobox(("Hitmarker"), { "Off", "Door", "Metallic", "Scaleform", "Warning", "Bell", "Custom" }, Config.Hitmarker);
		zgui::checkbox(("Bullet Tracer"), Config.Tracer);
		if (Config.Tracer) {
			zgui::slider_int(("Tracer Life"), 0, 5, Config.HitmarkerTime);
			zgui::combobox(("Tracer Material"), { "Blue Glow", "Bubble", "Glow", "Physbeam", "Purple Glow", "Purple Laser", "Radio", "White" }, Config.TracerMaterial);
		}
		zgui::checkbox(("Fake Duck"), Config.FakeDuck);
		zgui::key_bind(("Fake Duck Key"), Config.FakeduckKey);
		zgui::checkbox(("Clantag"), Config.Clantag);

		zgui::end_groupbox();
	}
	zgui::same_line();
	zgui::next_column(200, 10);

	zgui::begin_groupbox(("Fake Lag"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::checkbox(("Fake Lag"), Config.FakeLagEnable);
		if (Config.FakeLagEnable) {
			zgui::checkbox(("While Shooting"), Config.FakeLagShooting);
			zgui::combobox(("Type"), { "Static", "Random", "Peek" }, Config.FakelagType);
			if (Config.FakelagType == 1)
				zgui::slider_int(("Random Threshold"), 0, 6, Config.FakelagThreshold);
			zgui::slider_int(("Limit"), 0, 17, Config.Fakelag);
		}
		zgui::combobox(("Slow Walk"), { "Off", "Anti-Aim", "Speed", "Exploit" }, Config.SlowWalk); // <-- lol
		if (Config.SlowWalk == 2) {
			zgui::slider_int(("Speed"), 0, 100, Config.SlowWalkSlider);
		}
		if (Config.SlowWalk == 3) {
			zgui::key_bind(("Tick Count Exploit Key"), Config.SlowWalkExploitKey);
		}
		zgui::checkbox(("Third Person"), Config.Thirdperson);
		zgui::key_bind(("Third Person Key"), Config.ThirdpersonKey);
		zgui::checkbox(("Show Impacts"), Config.Impacts);
		zgui::checkbox(("Aspect Ratio"), Config.AspectRatio);
		if (Config.AspectRatio) {
			zgui::slider_int(("Value"), 0, 500, Config.AspectRatioSlider);
		}
		zgui::combobox(("Font"), { "Small Fonts", "Meme" }, Config.Font);

		zgui::end_groupbox();
		zgui::same_line();
		zgui::next_column(200, 10);
		zgui::begin_groupbox(("Buy Bot"), { 200 , 400 }, zgui::zgui_window_flags_none);
		{
			zgui::checkbox(("Enable Buy Bot"), Config.BuyBot.enable);
			zgui::combobox(("Primary Weapons"), { "Atuo", "Awp", "Scout" }, Config.BuyBot.main);
			zgui::combobox(("Secondary Weapons"), { "deagle/resolver", "duals" }, Config.BuyBot.second);
			zgui::combobox(("Armr"), { "Full Armor" }, Config.BuyBot.ammo);
			zgui::combobox(("Grenades"), { "None", "All" }, Config.BuyBot.grenade);
			zgui::end_groupbox();
		}
	}
}

static bool unload;	
void  Menu::cfgtab()
{
	zgui::next_column(100, 10);


	zgui::begin_groupbox(("Configs"), { 200 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::combobox(("Configs"), { "Alpha", "Bravo", "Charlie", "Delta" }, Tabs.Config);
		zgui::end_groupbox();
	}
	zgui::same_line();
	zgui::next_column(230, 10);
	zgui::begin_groupbox(("Functions"), { 200 , 240 }, zgui::zgui_window_flags_none);
	{
		auto cfilter = CHudChat::ChatFilters::CHAT_FILTER_NONE;
		if (Tabs.Config == 0 && zgui::button(("Load"), { 50,20 })) {
			if (g_pEngine->IsInGame() && g_pEngine->IsConnected()) g_ChatElement->ChatPrintf(0, cfilter, (" \x0D[Cash Hack] \x01""config loaded"" "));
			g_Config->Load();
		}
		else if (Tabs.Config == 1 && zgui::button(("Load"), { 50,20 })) {
			if (g_pEngine->IsInGame() && g_pEngine->IsConnected()) g_ChatElement->ChatPrintf(0, cfilter, (" \x0D[Cash Hack] \x01""config loaded"" "));
			g_Config->Load2();
		}
		else if (Tabs.Config == 2 && zgui::button(("Load"), { 50,20 })) {
			if (g_pEngine->IsInGame() && g_pEngine->IsConnected()) g_ChatElement->ChatPrintf(0, cfilter, (" \x0D[Cash Hack] \x01""config loaded"" "));
			g_Config->Load3();
		}
		else if (Tabs.Config == 3 && zgui::button(("Load"), { 50,20 })) {
			if (g_pEngine->IsInGame() && g_pEngine->IsConnected()) g_ChatElement->ChatPrintf(0, cfilter, (" \x0D[Cash Hack] \x01""config loaded"" "));
			g_Config->Load4();
		}

		if (Tabs.Config == 0 && zgui::button((" Save"), { 50,20 })) {
			if (g_pEngine->IsInGame() && g_pEngine->IsConnected()) g_ChatElement->ChatPrintf(0, cfilter, (" \x0D[Cash Hack] \x01""config saved"" "));
			g_Config->Save();
		}
		else if (Tabs.Config == 1 && zgui::button((" Save"), { 50,20 })) {
			if (g_pEngine->IsInGame() && g_pEngine->IsConnected()) g_ChatElement->ChatPrintf(0, cfilter, (" \x0D[Cash Hack] \x01""config saved"" "));
			g_Config->Save2();
		}
		else if (Tabs.Config == 2 && zgui::button((" Save"), { 50,20 })) {
			if (g_pEngine->IsInGame() && g_pEngine->IsConnected()) g_ChatElement->ChatPrintf(0, cfilter, (" \x0D[Cash Hack] \x01""config saved"" "));
			g_Config->Save3();
		}
		else if (Tabs.Config == 3 && zgui::button((" Save"), { 50,20 })) {
			if (g_pEngine->IsInGame() && g_pEngine->IsConnected()) g_ChatElement->ChatPrintf(0, cfilter, (" \x0D[Cash Hack] \x01""config saved"" "));
			g_Config->Save4();
		}
		if (zgui::button("Unload", { 50, 20 })) {
			Hooks::Restore();
		}
		zgui::text("");
		std::stringstream ss;
		ss << ("Build Date: ") << __DATE__ << " " << __TIME__; 
		zgui::text(ss.str().c_str()); 
		zgui::end_groupbox();

	}
}

void  Menu::exploitstab()
{
	zgui::next_column(100, 10);


	zgui::begin_groupbox(("Exploits"), { 220 , 400 }, zgui::zgui_window_flags_none);
	{
		zgui::checkbox("Tick Manipulation", Config.Exploit.TickManipulation);
		zgui::key_bind("Tick Manipulation Key", Config.Exploit.TickManipulationKey);		
		zgui::checkbox("Legit Teleportation", Config.Exploit.TickFreeze);
		zgui::key_bind("Legit Teleportation Key", Config.Exploit.TickFreezeKey);	
		zgui::checkbox("Lag Exploit", Config.Exploit.CrashExploit);

	}
		zgui::end_groupbox();
}



void Menu::debugtab()
{
	zgui::next_column(100, 10);

	zgui::begin_groupbox(("Update Log"), { 220 , 400 }, zgui::zgui_window_flags_none);
	{		
		zgui::text("9/8/19");
		zgui::text("Menu Changes");
		zgui::text("Added Pitch");
		zgui::text("Slow Walk Fix");
		zgui::text("General Improvements");
		zgui::text("Resolver Improvements");
		
	}
		zgui::end_groupbox();
}