// Copyright (C) 2009-2011 Josiah Hartzell (Skyreign Software)
// This file is part of the "irrBullet" Bullet physics extension library and wrapper.
// For conditions of distribution and use, see license in irrbullet.h
// The above copyright notice and its accompanying information must remain here.

#pragma once

#define BIT(x) (1<<(x)) // For collision masking

#include <matrix4.h>
#include <ISceneNode.h>

struct SWheelInfo;
class btVector3;
class btTransform;
struct btWheelInfo;


//void QuaternionToEuler(const btQuaternion &TQuat, btVector3 &TEuler);
void btTransformToIrrlichtMatrix(const btTransform& worldTrans, irr::core::matrix4& matr);

void btTransformFromIrrlichtMatrix(const irr::core::matrix4& irrmat, btTransform& transform);

void btWheelInfoToSWheelInfo(const btWheelInfo& btInfo, SWheelInfo& info, const btTransform& transform);

void btWheelInfoFromSWheelInfo(const SWheelInfo& info, btWheelInfo& btInfo);

irr::core::vector3df compensateForNodeType(const irr::core::vector3df& scale, irr::scene::ESCENE_NODE_TYPE type);

btVector3 irrlichtToBulletVector(const irr::core::vector3df& vec);

//btVector3 irrlichtToBulletVector(float x, float y, float z)
//{
//	return btVector3(x, y, z);
//}

irr::core::vector3df bulletToIrrlichtVector(const btVector3& vec);

template<class T1, class T2, class T3>
irr::core::vector3df bulletToIrrlichtVector(T1 x, T2 y, T3 z)
{
	return irr::core::vector3df(x, y, z);
}



enum class irrPhysicsDebugMode
{
  EPDM_NoDebug = 0,
  EPDM_DrawWireframe = 1,
  EPDM_DrawAabb = 2,
  EPDM_DrawFeaturesText = 4,
  EPDM_DrawContactPoints = 8,
  EPDM_NoDeactivation = 16,
  EPDM_NoHelpText = 32,
  EPDM_DrawText = 64,
  EPDM_ProfileTimings = 128,
  EPDM_EnableSatComparison = 256,
  EPDM_DisableBulletLCP = 512,
  EPDM_EnableCCD = 1024,
  EPDM_DrawConstraints = (1 << 11),
  EPDM_DrawConstraintLimits = (1 << 12),
  EPDM_FastWireframe = (1<<13),
  EPDM_MAX_DEBUG_DRAW_MODE
};

inline irrPhysicsDebugMode operator|(irrPhysicsDebugMode a, irrPhysicsDebugMode b)
{
	return static_cast<irrPhysicsDebugMode>(static_cast<int>(a) | static_cast<int>(b));
}