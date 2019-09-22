#include "chams.h"
#include <fstream>
#include "../../SDK/texture_group_names.h"
#include "../../Menu/Menu.h"
#include "../../Utils/GlobalVars.h"
#include "..\Aimbot\LagComp.h"
#include "../Aimbot/Aimbot.h"
#include "../../Hooks.h"

Chams g_Chams;

int Record = 0;

IMaterial* btchammat = nullptr;

IMaterial* Meme = nullptr;

void Chams::BacktrackChams(void* ecx, void* edx, IMatRenderContext* context, const DrawModelState_t& state, const ModelRenderInfo_t& info, matrix3x4_t* matrix)
{
	static auto fnDME = g_Hooks.pModelHook->GetOriginal<Hooks::DrawModelExecute_t>(vtable_indexes::dme);

	const auto mdl = info.pModel;

	C_BaseEntity* pPlayerEntity = g_pEntityList->GetClientEntity(info.index);

	bool is_player = strstr(mdl->szName, "models/player") != nullptr;

	if (is_player && g_Menu.Config.Backtrackchams)
	{
		auto btcolor = g_Menu.Config.BacktrackchamsColor;

		if (g_Menu.Config.ShadowMaterial == 0) {
			btchammat = g_pMaterialSys->FindMaterial("models/inventory_items/dogtags/dogtags_outline", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 1) {
			btchammat = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/gloss", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 2) {
			btchammat = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/crystal_clear", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 3) {
			btchammat = g_pMaterialSys->FindMaterial("models/inventory_items/cologne_prediction/cologne_prediction_glass", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 4) {
			btchammat = g_pMaterialSys->FindMaterial("models/gibs/glass/glass", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 5) {
			btchammat = g_pMaterialSys->FindMaterial("models/inventory_items/dogtags/dogtags_lightray", "Other textures");
		}
		btchammat->AlphaModulate(0.30f);
		btchammat->ColorModulate(btcolor.r / 255.0f, btcolor.g / 255.0f, btcolor.b / 255.0f);
		btchammat->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);

		C_BaseEntity* ent = g_pEntityList->GetClientEntity(info.index);

		if (g::pLocalEntity && ent && ent != g::pLocalEntity && !ent->IsDormant() && ent->IsAlive() && ent->GetTeam() != g::pLocalEntity->GetTeam() && g::pLocalEntity->IsAlive())
		{
			for (int t = 0; t < g_LagComp.PlayerRecord[ent->EntIndex()].size(); t++)
			{
				if (g_LagComp.PlayerRecord[ent->EntIndex()].at(t).boneMatrix &&  g_LagComp.PlayerRecord[ent->EntIndex()].at(t).SimTime &&  g_LagComp.PlayerRecord[ent->EntIndex()].at(t).boneMatrix)
				{
					if ( g_LagComp.PlayerRecord[ent->EntIndex()].size() > 1 && ent->GetVelocity().Length() > 1)
					{
						g_pModelRender->ForcedMaterialOverride(btchammat);
						//Record = g_LagComp.PlayerRecord[info.index].size() - 1; //use this if u want 1 record and remove the for loop
						//if (g_LagComp.ShotTick[info.index] != -1)
						//	Record = g_LagComp.ShotTick[info.index];
						fnDME(ecx, context, state, info, g_LagComp.PlayerRecord[info.index].at(t).Matrix);
						g_pModelRender->ForcedMaterialOverride(nullptr);
					}
				}
			}
		}
	}
	if (g_Menu.Config.FakeLagModel)
	{
		if (g_Menu.Config.ShadowMaterial == 0) {
			Meme = g_pMaterialSys->FindMaterial("models/inventory_items/dogtags/dogtags_outline", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 1) {
			Meme = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/gloss", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 2) {
			Meme = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/crystal_clear", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 3) {
			Meme = g_pMaterialSys->FindMaterial("models/inventory_items/cologne_prediction/cologne_prediction_glass", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 4) {
			Meme = g_pMaterialSys->FindMaterial("models/gibs/glass/glass", "Other textures");
		}
		else if (g_Menu.Config.ShadowMaterial == 5) {
			Meme = g_pMaterialSys->FindMaterial("models/inventory_items/dogtags/dogtags_lightray", "Other textures");
		}

		if (pPlayerEntity && pPlayerEntity->IsAlive() && !pPlayerEntity->IsDormant() && g_Aimbot.Matrix[info.index] && strstr(mdl->szName, "models/player") && g_Menu.Config.FakeLagModel && g::pLocalEntity->GetVelocity().Length() > g_Menu.Config.StaticDesync ? 3 : 0.1f) {
			if (pPlayerEntity == g::pLocalEntity) {
				Meme->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);
				Meme->AlphaModulate(g_Menu.Config.FakeLagModelColor.a / 255.f);
				Meme->ColorModulate(g_Menu.Config.FakeLagModelColor.r / 255.f, g_Menu.Config.FakeLagModelColor.g / 255.f, g_Menu.Config.FakeLagModelColor.b / 255.f);
				g_pModelRender->ForcedMaterialOverride(Meme);
				fnDME(ecx, context, state, info, g_Aimbot.Matrix[info.index]);
				g_pModelRender->ForcedMaterialOverride(nullptr);
			}
		}
	}
}
void Chams::OnDrawModelExecute(
	void* ecx, void* edx, IMatRenderContext* context, const DrawModelState_t& state, const ModelRenderInfo_t& info, matrix3x4_t* matrix)
{
	static auto fnDME = g_Hooks.pModelHook->GetOriginal<Hooks::DrawModelExecute_t>(vtable_indexes::dme);


	const char* ModelName = g_pModelInfo->GetModelName((model_t*)info.pModel);

	bool is_player = strstr(ModelName, "models/player");
	bool is_sleeve = strstr(ModelName, "sleeve");
	bool is_arm = strstr(ModelName, "arms");
	bool is_chicken = strstr(ModelName, "models/chicken");

	static IMaterial* Material = nullptr;
	static IMaterial* HandMaterial = nullptr;
	static IMaterial* WeaponMaterial = nullptr;
	static IMaterial* ChickenMaterial = nullptr;

	if (!g::pLocalEntity || !g_pEngine->IsInGame() || !g_pEngine->IsConnected())
	{
		Material = nullptr;
		HandMaterial = nullptr;
		return;
	}

	if (g_Menu.Config.ChamsMaterial == 0) {
		Material = g_pMaterialSys->FindMaterial(("vitality_metallic"), "Model textures");
	}
	else if (g_Menu.Config.ChamsMaterial == 1) {
		Material = g_pMaterialSys->FindMaterial(("yeti_flat"), "Model textures");
	}
	else if (g_Menu.Config.ChamsMaterial == 2) {
		Material = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/crystal_blue", "Other textures");
	}
	else if (g_Menu.Config.ChamsMaterial == 3) {
		Material = g_pMaterialSys->FindMaterial("models/inventory_items/dogtags/dogtags_outline", "Other textures");
	}

	else if (g_Menu.Config.ChamsMaterial == 4) {
		Material = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/gold", "Other textures");
	}

	if (g_Menu.Config.HandChamsMaterial == 0) { // because there is fucking selection menu and i dont want to make it :)
		HandMaterial = g_pMaterialSys->FindMaterial(("vitality_metallic"), "Model textures");
	}
	else if (g_Menu.Config.HandChamsMaterial == 1) {
		HandMaterial = g_pMaterialSys->FindMaterial(("yeti_flat"), "Model textures");
	}
	else if (g_Menu.Config.HandChamsMaterial == 2) {
		HandMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/crystal_blue", "Other textures");
	}
	else if (g_Menu.Config.HandChamsMaterial == 3) {
		HandMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/dogtags/dogtags_outline", "Other textures");
	}
	else if (g_Menu.Config.HandChamsMaterial == 4) {
		HandMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/gold", "Other textures");
	}
	else if (g_Menu.Config.HandChamsMaterial == 5) {
		HandMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/gloss", "Other textures");
	}
	else if (g_Menu.Config.HandChamsMaterial == 6) {
		HandMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/crystal_clear", "Other textures");
	}
	else if (g_Menu.Config.HandChamsMaterial == 7) {
		HandMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/cologne_prediction/cologne_prediction_glass", "Other textures");
	}

	if (g_Menu.Config.WeaponChamsMaterial == 0) { // because there is fucking selection menu and i dont want to make it :)
		WeaponMaterial = g_pMaterialSys->FindMaterial(("vitality_metallic"), "Model textures");
	}
	else if (g_Menu.Config.WeaponChamsMaterial == 1) {
		WeaponMaterial = g_pMaterialSys->FindMaterial(("yeti_flat"), "Model textures");
	}
	else if (g_Menu.Config.WeaponChamsMaterial == 2) {
		WeaponMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/crystal_blue", "Other textures");
	}
	else if (g_Menu.Config.WeaponChamsMaterial == 3) {
		WeaponMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/dogtags/dogtags_outline", "Other textures");
	}
	else if (g_Menu.Config.WeaponChamsMaterial == 4) {
		WeaponMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/gold", "Other textures");
	}
	else if (g_Menu.Config.WeaponChamsMaterial == 5) {
		WeaponMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/gloss", "Other textures");
	}
	else if (g_Menu.Config.WeaponChamsMaterial == 6) {
		WeaponMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/trophy_majors/crystal_clear", "Other textures");
	}
	else if (g_Menu.Config.WeaponChamsMaterial == 7) {
		WeaponMaterial = g_pMaterialSys->FindMaterial("models/inventory_items/cologne_prediction/cologne_prediction_glass", "Other textures");
	}


	if (is_player) {
		auto ent = g_pEntityList->GetClientEntity(info.index);

		if (ent && g::pLocalEntity && ent->IsAlive()) {
			if (ent == g::pLocalEntity) {
				if (g_Menu.Config.LocalChams) {
					Material->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
					Material->AlphaModulate(g_Menu.Config.LocalChamsColor.a / 255.f);
					Material->ColorModulate(g_Menu.Config.LocalChamsColor.r / 255.f, g_Menu.Config.LocalChamsColor.g / 255.f, g_Menu.Config.LocalChamsColor.b / 255.f);
					g_pModelRender->ForcedMaterialOverride(Material);
					fnDME(ecx, context, state, info, matrix);
					g_pModelRender->ForcedMaterialOverride(nullptr);
				}

				if (g_Menu.Config.desyncChams) {
					IMaterial* dagTag = g_pMaterialSys->FindMaterial("models/inventory_items/dogtags/dogtags_outline", "Other textures");

					Vector OrigAng;
					OrigAng = g::pLocalEntity->GetAbsAngles();

					Material->AlphaModulate(255.f);
					Material->ColorModulate(255.f, 255.f, 255.f);

					g_pModelRender->ForcedMaterialOverride(dagTag);

					fnDME(ecx, context, state, info, matrix);

					g_pModelRender->ForcedMaterialOverride(nullptr);

					g::pLocalEntity->SetAngle2(Vector(0, g::FakeAngle.y, 0));
					g::pLocalEntity->SetAngle2(OrigAng);
				}
			}

			const auto enemy = ent->GetTeam() != g::pLocalEntity->GetTeam();
			if (!enemy)
				return;

			if (g_Menu.Config.ChamsXQZ) {
				Material->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
				Material->AlphaModulate(g_Menu.Config.ChamsColor.a / 255.f);
				Material->ColorModulate(g_Menu.Config.ChamsColor.r / 255.f, g_Menu.Config.ChamsColor.g / 255.f, g_Menu.Config.ChamsColor.b / 255.f);
				g_pModelRender->ForcedMaterialOverride(Material);
				fnDME(ecx, context, state, info, matrix);
				g_pModelRender->ForcedMaterialOverride(nullptr);
			}

			if (g_Menu.Config.Chams) {
				Material->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);
				Material->AlphaModulate(g_Menu.Config.XQZ.a / 255.f);
				Material->ColorModulate(g_Menu.Config.XQZ.r / 255.f, g_Menu.Config.XQZ.g / 255.f, g_Menu.Config.XQZ.b / 255.f);
				g_pModelRender->ForcedMaterialOverride(Material);
				fnDME(ecx, context, state, info, matrix);
				g_pModelRender->ForcedMaterialOverride(nullptr);
			}
		}
	}
	if (is_arm) {
		auto material = g_pMaterialSys->FindMaterial(ModelName, TEXTURE_GROUP_MODEL);
		if (!material)
			return;
		if (g_Menu.Config.HandChams) {
			HandMaterial->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);
			HandMaterial->AlphaModulate(g_Menu.Config.HandChamsColor.a / 255.f);
			HandMaterial->ColorModulate(g_Menu.Config.HandChamsColor.r / 255.f, g_Menu.Config.HandChamsColor.g / 255.f, g_Menu.Config.HandChamsColor.b / 255.f);
			g_pModelRender->ForcedMaterialOverride(HandMaterial);
			fnDME(ecx, context, state, info, matrix);
			g_pModelRender->ForcedMaterialOverride(nullptr);
		}
	}
	if (strstr(ModelName, "models/weapons/v_") && !strstr(ModelName, "arms")) {
		auto material = g_pMaterialSys->FindMaterial(ModelName, TEXTURE_GROUP_MODEL);
		if (!material)
			return;
		if (g_Menu.Config.WeaponChams)
		{
			
			WeaponMaterial->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);
			WeaponMaterial->AlphaModulate(g_Menu.Config.WeaponChamsColor.a / 255.f);
			WeaponMaterial->ColorModulate(g_Menu.Config.WeaponChamsColor.r / 255.f, g_Menu.Config.WeaponChamsColor.g / 255.f, g_Menu.Config.WeaponChamsColor.b / 255.f);
			g_pModelRender->ForcedMaterialOverride(WeaponMaterial);
			fnDME(ecx, context, state, info, matrix);
			g_pModelRender->ForcedMaterialOverride(nullptr);

		}
		
	}	
	if (is_chicken) {
		auto ent = g_pEntityList->GetClientEntity(info.index);
		ChickenMaterial = g_pMaterialSys->FindMaterial(("vitality_metallic"), "Model textures");
		auto material = g_pMaterialSys->FindMaterial(ModelName, TEXTURE_GROUP_MODEL);
		if (!material)
			return;
		if (g_Menu.Config.ChickenChams) 
		{
			
			ChickenMaterial->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);
			ChickenMaterial->AlphaModulate(g_Menu.Config.ChickenChamsColor.a / 255.f);
			ChickenMaterial->ColorModulate(g_Menu.Config.ChickenChamsColor.r / 255.f, g_Menu.Config.ChickenChamsColor.g / 255.f, g_Menu.Config.ChickenChamsColor.b / 255.f);
			g_pModelRender->ForcedMaterialOverride(WeaponMaterial);
			fnDME(ecx, context, state, info, matrix);
			g_pModelRender->ForcedMaterialOverride(nullptr);

		}
		
	}
}