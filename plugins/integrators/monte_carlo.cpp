#include <nori/integrator.h>
#include <nori/scene.h>

NORI_NAMESPACE_BEGIN

class MonteCarloIntegrator : public Integrator {
public:
    MonteCarloIntegrator(const PropertyList &props) {
        /* No parameters this time */
    }

    Color3f Li(const Scene *scene, Sampler *sampler, const Ray3f &ray) const {
        /* Find the surface that is visible in the requested direction */
        Intersection its;
        if (!scene->rayIntersect(ray, its))
            return Color3f(0.0f);

        /* Return the component-wise absolute
           value of the shading normal as a color */
        Normal3f n = its.shFrame.n.cwiseAbs();
        
        return Color3f(n.x(), n.y(), n.z());
    }

    std::string toString() const {
        return "MonteCarloIntegrator[]";
    }
};

NORI_REGISTER_CLASS(MonteCarloIntegrator, "monte_carlo");
NORI_NAMESPACE_END