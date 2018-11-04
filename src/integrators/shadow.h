
/*
 Shadow Integrator 
 */

#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef PBRT_INTEGRATORS_SHADOW_H
#define PBRT_INTEGRATORS_SHADOW_H

// integrators/shadow.h*
#include "pbrt.h"
#include "integrator.h"
#include "scene.h"
#include "directlighting.h"

namespace pbrt {



// ShadowIntegrator Declarations
class ShadowIntegrator : public SamplerIntegrator {
  public:
    // ShadowIntegrator Public Methods
    ShadowIntegrator(LightStrategy strategy, int maxDepth,
                             std::shared_ptr<const Camera> camera,
                             std::shared_ptr<Sampler> sampler,
                             const Bounds2i &pixelBounds)
        : SamplerIntegrator(camera, sampler, pixelBounds),
          strategy(strategy),
          maxDepth(maxDepth) {}
    Spectrum Li(const RayDifferential &ray, const Scene &scene,
                Sampler &sampler, MemoryArena &arena, int depth) const;
    void Preprocess(const Scene &scene, Sampler &sampler);

  private:
    // ShadowIntegrator Private Data
    const LightStrategy strategy;
    const int maxDepth;
    std::vector<int> nLightSamples;
};

ShadowIntegrator *CreateShadowIntegrator(
    const ParamSet &params, std::shared_ptr<Sampler> sampler,
    std::shared_ptr<const Camera> camera);

}  // namespace pbrt

#endif  // PBRT_INTEGRATORS_SHADOW_H
