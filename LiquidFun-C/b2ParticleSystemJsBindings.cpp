#include<Box2D/Box2D.h>
#include <stdio.h>
// TODO add setDamping, setRadius
extern "C"
{
	
	__declspec(dllexport) double b2ParticleSystem_CreateParticle(void* particleSystem,
		//particleDef
		double colorR, double colorB, double colorG, double colorA,
		double flags, double group, double lifetime, double positionX,
		double positionY, double userData, double velocityX, double velocityY) {
	  b2ParticleDef def;
	  def.color = b2ParticleColor(colorR, colorG, colorB, colorA);
	  def.flags = flags;
	  def.group = (b2ParticleGroup*)&group;
	  def.lifetime = lifetime;
	  def.position = b2Vec2(positionX, positionY);
	  def.userData = (double*)&userData;
	  def.velocity = b2Vec2(velocityX, velocityY);

	  return ((b2ParticleSystem*)particleSystem)->CreateParticle(def);
	}
	

// Shapes array is not currently supported for b2ParticleSystems

__declspec(dllexport) void* b2ParticleSystem_GetColorBuffer(void* particleSystem) {
  return ((b2ParticleSystem*)particleSystem)->GetColorBuffer();
}
__declspec(dllexport) double b2ParticleSystem_GetParticleCount(void* particleSystem) {
  return ((b2ParticleSystem*)particleSystem)->GetParticleCount();
}

__declspec(dllexport) void* b2ParticleSystem_GetPositionBuffer(void* particleSystem) {
  return ((b2ParticleSystem*)particleSystem)->GetPositionBuffer();
}
__declspec(dllexport) void* b2ParticleSystem_GetVelocityBuffer(void* particleSystem) {
  return ((b2ParticleSystem*)particleSystem)->GetVelocityBuffer();
}
__declspec(dllexport) void b2ParticleSystem_SetDamping(void* particleSystem, double damping) {
  ((b2ParticleSystem*)particleSystem)->SetDamping(damping);
}
__declspec(dllexport) void b2ParticleSystem_SetDensity(void* particleSystem, double density) {
  ((b2ParticleSystem*)particleSystem)->SetDensity(density);
}

__declspec(dllexport) void b2ParticleSystem_SetRadius(void* particleSystem, double radius) {
  ((b2ParticleSystem*)particleSystem)->SetRadius(radius);
}

}