#include "Menu.h"
#include "TGFCfg.h"

void CConfig::Setup()
{
	SetupValue(g_Menu.Config.Aimbot, false, ("aimbot"));
	SetupValue(g_Menu.Config.Hitchance, 0, ("hitchance"));
	SetupValue(g_Menu.Config.HitchanceValue, 0, ("hitchanceval"));
	SetupValue(g_Menu.Config.Mindmg, 0, ("mindmg"));
	SetupValue(g_Menu.Config.Resolver, false, ("resolver"));
	SetupValue(g_Menu.Config.OnShotAA, false, ("onshotantiaim"));
	SetupValue(g_Menu.Config.ResolverType, 0, ("resolvertype"));
	SetupValue(g_Menu.Config.BodyScale, 0, ("bodyscale"));
	SetupValue(g_Menu.Config.HeadScale, 0, ("headscale"));
	SetupValue(g_Menu.Config.MultiPoint, false, ("multipoint"));
	SetupValue(g_Menu.Config.DelayShot, false, ("delayshot"));
	SetupValue(g_Menu.Config.IgnoreLimbs, false, ("ignorelimbs"));
	SetupValue(g_Menu.Config.PredictFakeLag, false, ("whywontthisfuckingwork"));
	SetupValue(g_Menu.Config.OutOfView, false, ("playerindicator"));
	SetupValue(g_Menu.Config.Autostop, false, ("autostop"));
	SetupValue(g_Menu.Config.FixShotPitch, false, ("fixshotpitch"));
	SetupValue(g_Menu.Config.ShotBacktrack, false, ("shotbacktrk"));
	SetupValue(g_Menu.Config.PosBacktrack, false, ("posbacktrk"));
	SetupValue(g_Menu.Config.BaimLethal, false, ("baimlethal"));
	SetupValue(g_Menu.Config.BaimLethal, false, ("baimlethal"));
	SetupValue(g_Menu.Config.BaimPitch, false, ("bamepitch"));
	SetupValue(g_Menu.Config.BaimInAir, false, ("baiminair"));
	SetupValue(g_Menu.Config.BaimAlways, false, ("baimalways"));
	SetupValue(g_Menu.Config.BaimAfterEnable, false, ("baimafterenable"));
	SetupValue(g_Menu.Config.BaimSlider, 0, ("baimafterx"));
	SetupValue(g_Menu.Config.BaimLethalSlider, 0, ("baimathealth"));
	SetupValue(g_Menu.Config.MarkerSize, 0, ("hitmarkersize"));
	SetupValue(g_Menu.Config.ExpireTime, 0, ("hitmarkerexptime"));
	SetupValue(g_Menu.Config.VisHitDmg, false, ("hitmarkervisdmg"));
	SetupValue(g_Menu.Config.VisHitmarker, false, ("hitmarkervis"));
	SetupValue(g_Menu.Config.ShowAimSpot, false, ("showaimspot"));

	SetupValue(g_Menu.Config.Antiaim, false, ("antiaimd"));
	SetupValue(g_Menu.Config.DesyncAngle, false, ("desyncang"));
	SetupValue(g_Menu.Config.Jitter, 0, ("jitterenable"));
	SetupValue(g_Menu.Config.JitterRange, 0, ("jitterrange"));
	SetupValue(g_Menu.Config.FakeLagModel, 0, ("fakelagmodel"));
	SetupValue(g_Menu.Config.ShadowMaterial, 0, ("shadowmat"));
	SetupValue(g_Menu.Config.FakeLagModelColor, 0, ("fakelagmodelcolor"));
	SetupValue(g_Menu.Config.Fakelag, 0, ("fakelag"));
	SetupValue(g_Menu.Config.FakeLagOnPeek, false, ("onpeekflag"));
	SetupValue(g_Menu.Config.FakeLagEnable, false, ("fakelagenablememe"));
	SetupValue(g_Menu.Config.FakelagThreshold, false, ("randthreshold"));
	SetupValue(g_Menu.Config.FakelagType, false, ("fakelagtypebr0"));
	SetupValue(g_Menu.Config.ChokeShotOnPeek, false, ("chokeshotonpeek"));
	SetupValue(g_Menu.Config.DesyncAngle, false, ("desyncangle"));
	SetupValue(g_Menu.Config.BackAA, false, ("backaa"));
	SetupValue(g_Menu.Config.Freestand, false, ("freestand"));

	SetupValue(g_Menu.Config.Hitboxes, false, ("hitboxes"));
	SetupValue(g_Menu.Config.Head, false, ("head"));
	SetupValue(g_Menu.Config.Chest, false, ("chest"));
	SetupValue(g_Menu.Config.Pelvis, false, ("pelvis"));
	SetupValue(g_Menu.Config.Arms, false, ("arms"));
	SetupValue(g_Menu.Config.Legs, false, ("legs"));

	SetupValue(g_Menu.Config.Info, false, ("Info"));
	SetupValue(g_Menu.Config.AAInvertIndicators, false, ("aainvertindicators"));
	SetupValue(g_Menu.Config.Esp, false, ("esp"));
	SetupValue(g_Menu.Config.LocalChams, false, ("localchamsa"));
	SetupValue(g_Menu.Config.Font, 0, ("font"));
	SetupValue(g_Menu.Config.DesyncInvertKey, 0, ("desyncinvertkey"));
	SetupValue(g_Menu.Config.ChamsMaterial, 0, ("chamsmaterial"));
	SetupValue(g_Menu.Config.AsusProps, 90, ("asusprops"));
	SetupValue(g_Menu.Config.LBYDelta, 90, ("lbydelta"));
	SetupValue(g_Menu.Config.FontColor, 255, ("fontclr"));
	SetupValue(g_Menu.Config.ChamsColor, 255, ("chamscolor"));
	SetupValue(g_Menu.Config.XQZ, 255, ("xqzcolor"));
	SetupValue(g_Menu.Config.OutOfViewColor, 255, ("outofviewindicatorcolor"));
	SetupValue(g_Menu.Config.ImpactColor, 255, ("impact_color"));
	SetupValue(g_Menu.Config.WepColor, 255, ("weaponcolor"));
	SetupValue(g_Menu.Config.LocalChamsColor, 255, ("local_chamscolor"));
	SetupValue(g_Menu.Config.SpreadColor, 255, ("showspreadcolor"));
	SetupValue(g_Menu.Config.BoxColor, 255, ("boxcolor"));
	SetupValue(g_Menu.Config.SkyboxColor, 255, ("skyboxcolor"));
	SetupValue(g_Menu.Config.HitmarkerColor, 255, ("hitmarkercolor"));
	SetupValue(g_Menu.Config.Name, false, ("name")); 
	SetupValue(g_Menu.Config.FakeLagShooting, false, ("shotfakelag")); 
	SetupValue(g_Menu.Config.Weapon, false, ("weapon"));
	SetupValue(g_Menu.Config.FreestandType, 0, ("freestandtype"));
	SetupValue(g_Menu.Config.Yaw, 180, ("yawaddvalue"));
	SetupValue(g_Menu.Config.Box, false, ("box"));
	SetupValue(g_Menu.Config.BoxColor, 255, ("boxclr"));
	SetupValue(g_Menu.Config.HandChams, false, ("handchams"));
	SetupValue(g_Menu.Config.HandChamsColor, 255, ("handchamscolor"));
	SetupValue(g_Menu.Config.HandChamsMaterial, 0, ("handchamsmaterial"));
	SetupValue(g_Menu.Config.WeaponChamsMaterial, 0, ("weaponchamsmaterial"));
	SetupValue(g_Menu.Config.Glow, false, ("glowenable"));
	SetupValue(g_Menu.Config.GlowColor, 255, ("glowcolor"));
	SetupValue(g_Menu.Config.HealthBar, false, ("healthbar"));
	SetupValue(g_Menu.Config.Thirdperson, false, ("thirdpersonbruh"));
	SetupValue(g_Menu.Config.DroppedWeapons, false, ("droppedweapons"));
	SetupValue(g_Menu.Config.AimRCS, false, ("aimrcsenable"));
	SetupValue(g_Menu.Config.EngineRadar, false, ("engineradar"));
	SetupValue(g_Menu.Config.Watermark, true, ("watermark"));
	SetupValue(g_Menu.Config.DrawHitboxTime, 0, ("hitboxtime"));
	SetupValue(g_Menu.Config.Clantag, false, ("clantag"));
	SetupValue(g_Menu.Config.infinite_duck, false, ("infinite crouch"));
	SetupValue(g_Menu.Config.Skeleton, false, 2, ("skeleton"));
	SetupValue(g_Menu.Config.ForcedConvars, false, 2, ("forcedcvars"));
	SetupValue(g_Menu.Config.DesyncType, false, ("desynctype"));
	SetupValue(g_Menu.Config.SkeletonColor, 255, ("skeletonclr"));
	SetupValue(g_Menu.Config.Backtrackchams, false, ("btchams"));
	SetupValue(g_Menu.Config.BacktrackchamsColor, 255, ("btchamscolor"));
	SetupValue(g_Menu.Config.HitboxPoints, false, ("hitboxpoints"));
	SetupValue(g_Menu.Config.Chams, false, ("chams"));
	SetupValue(g_Menu.Config.NoZoom, false, ("nozoom"));
	SetupValue(g_Menu.Config.NoScope, false, ("noscope"));
	SetupValue(g_Menu.Config.NoRecoil, false, ("norecoil"));
	SetupValue(g_Menu.Config.FakeChams, false, ("localchams"));
	SetupValue(g_Menu.Config.Arrows, false, ("localarrows"));
	SetupValue(g_Menu.Config.FixFeet, false, ("Fix Feet"));

	SetupValue(g_Menu.Config.DrawHitboxes, false, ("drawhitboxes"));

	SetupValue(g_Menu.Config.RCSamount, 0, ("rcsamount"));
	SetupValue(g_Menu.Config.RCStype, 0, ("rcst"));
	SetupValue(g_Menu.Config.RCS, 0, ("rcs"));
	SetupValue(g_Menu.Config.StandaloneRCS, 0, ("rcaaas"));
	SetupValue(g_Menu.Config.StandaloneRCSSlider, 0, ("raaaaaaaaacs"));
	SetupValue(g_Menu.Config.StandaloneRCStype, 0, ("rcaaaaasttt"));
	SetupValue(g_Menu.Config.LegitAA, false, ("legitaa"));
	SetupValue(g_Menu.Config.Legitbot, 0, ("legitenable"));
	SetupValue(g_Menu.Config.LegitBacktrack, 0, ("legitbtmeme"));
	SetupValue(g_Menu.Config.TracerMaterial, 0, ("tracermaterial"));

	SetupValue(g_Menu.Config.Fov, 0, ("fov"));
	SetupValue(g_Menu.Config.OutOfViewRadius, 0, ("outofviewradius"));
	SetupValue(g_Menu.Config.OutOfViewSize, 0, ("outofviewsize"));
	SetupValue(g_Menu.Config.Crosshair, false, 3, ("crosshair")); 
	SetupValue(g_Menu.Config.Flags, false, ("flags"));
	SetupValue(g_Menu.Config.Bhop, false, ("bhop"));
	SetupValue(g_Menu.Config.NoSmoke, false, ("noshmoke"));
	SetupValue(g_Menu.Config.AutoStrafe, false, ("autostrafe"));
	SetupValue(g_Menu.Config.Tracer, false, ("tracermeme"));
	SetupValue(g_Menu.Config.SpreadCrosshair, false, ("spreadcrosshairmeme"));
	SetupValue(g_Menu.Config.SkyboxMod, false, ("skyboxmod"));
	SetupValue(g_Menu.Config.RagdollMeme, false, ("ragdollmeme"));
	SetupValue(g_Menu.Config.AntiaimMonitor, false, ("antiaimmonitor"));
	SetupValue(g_Menu.Config.BombEsp, false, ("bombesp"));
	SetupValue(g_Menu.Config.Projectiles, false, ("projectiles"));
	SetupValue(g_Menu.Config.LocalFake, 0, ("fakehitbox"));
	SetupValue(g_Menu.Config.ChamsXQZ, false, ("projectiles"));
	SetupValue(g_Menu.Config.AtTarget, false, ("attargets"));
	SetupValue(g_Menu.Config.StaticDesync, false, ("staticdesync"));
	SetupValue(g_Menu.Config.Autoscope, false, ("autoscope"));
	SetupValue(g_Menu.Config.HitmarkerTime, 0, ("tracertime"));
	SetupValue(g_Menu.Config.Ak47meme, false, ("ak47meme"));
	SetupValue(g_Menu.Config.Hitmarker, 2, ("hitmarker"));
	SetupValue(g_Menu.Config.Impacts, 0, ("showimpacts"));
	SetupValue(g_Menu.Config.SlowWalkSlider , 0, ("slowwalkslider"));
	SetupValue(g_Menu.Config.SlowWalk, false, ("fakeduck"));
	SetupValue(g_Menu.Config.FakeDuck, false, ("slowwalk"));
	SetupValue(g_Menu.Config.FakeduckKey, 0, ("fakeduckkey"));
	SetupValue(g_Menu.Config.ThirdpersonKey, 0, ("thirdpersonkey"));
	SetupValue(g_Menu.Config.BaimKey, 0, ("baimkey"));

	SetupValue(g_Menu.Config.NightMode, false, ("nightmode"));
	SetupValue(g_Menu.Config.NightModeSlider, 0, ("nightmodeslider"));
	SetupValue(g_Menu.Config.PostProcess, false, ("postprocess"));
	SetupValue(g_Menu.Config.AspectRatio, false, ("aspect"));
	SetupValue(g_Menu.Config.AspectRatioSlider, 0, ("aspectslider"));
	SetupValue(g_Menu.Config.LegitAimbot, false, ("legitaimbot"));
	SetupValue(g_Menu.Config.AspectRatioSlider, 0, ("aspectslider"));
	SetupValue(g_Menu.Config.LegitFOV, 0, ("legitaimfov"));
	SetupValue(g_Menu.Config.LegitSmooth, 0, ("legitaimsmooth"));
	SetupValue(g_Menu.Config.Extrapolation, false, ("predictfakelag"));
	SetupValue(g_Menu.Config.Pitch, false, ("Pitch"));
	SetupValue(g_Menu.Config.SlowWalkBaim, false, ("Slow Walk Body Aim"));
}

void CConfig::SetupValue(int& value, int def, std::string name)
{
	value = def;
	ints.push_back(new ConfigValue< int >(name, &value));
}

void CConfig::SetupValue(float& value, float def, std::string name)
{
	value = def;
	floats.push_back(new ConfigValue< float >(name, &value));
}

void CConfig::SetupValue(bool& value, bool def, std::string name)
{
	value = def;
	bools.push_back(new ConfigValue< bool >(name, &value));
}

void CConfig::SetupValue(zgui::color& value, float def, std::string name)
{
	value.r = def;
	value.g = def;
	value.b = def;
	value.a = def;

	ints.push_back(new ConfigValue< int >(name + "red", &value.r));
	ints.push_back(new ConfigValue< int >(name + "green", &value.g));
	ints.push_back(new ConfigValue< int >(name + "blue", &value.b));
	ints.push_back(new ConfigValue< int >(name + "alpha", &value.a));
}
void CConfig::SetupValue(bool* value, bool def, int size, std::string name) // for multiboxes
{
	for (int c = 0; c < size; c++)
	{
		value[c] = def;

		name += std::to_string(c);

		bools.push_back(new ConfigValue< bool >(name, &value[c]));
	}
}

static char name[] = "Cash-Hack";

void CConfig::Save()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Cash-Hack\\");
		file = std::string(path) + ("\\Cash-Hack\\cfg.ini");
	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(name, value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(name, value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(name, value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Cash-Hack\\");
		file = std::string(path) + ("\\Cash-Hack\\cfg.ini");
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

void CConfig::Save2()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Cash-Hack\\");
		file = std::string(path) + ("\\Cash-Hack\\cfg2.ini");
	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(name, value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(name, value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(name, value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Load2()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Cash-Hack\\");
		file = std::string(path) + ("\\Cash-Hack\\cfg2.ini");
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

void CConfig::Save3()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Cash-Hack\\");
		file = std::string(path) + ("\\Cash-Hack\\cfg3.ini");
	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(name, value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(name, value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(name, value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Load3()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Cash-Hack\\");
		file = std::string(path) + ("\\Cash-Hack\\cfg3.ini");
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}


void CConfig::Save4()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Cash-Hack\\");
		file = std::string(path) + ("\\Cash-Hack\\cfg4.ini");
	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(name, value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(name, value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(name, value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Load4()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\Cash-Hack\\");
		file = std::string(path) + ("\\Cash-Hack\\cfg4.ini");
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(name, value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

CConfig* g_Config = new CConfig();