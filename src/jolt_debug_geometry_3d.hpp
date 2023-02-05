#pragma once

#include "jolt_debug_renderer.hpp"

class JoltDebugGeometry3D final : public GeometryInstance3D {
	GDCLASS_NO_WARN(JoltDebugGeometry3D, GeometryInstance3D) // NOLINT

public:
	enum ColorScheme {
		COLOR_SCHEME_INSTANCE,
		COLOR_SCHEME_SHAPE_TYPE,
		COLOR_SCHEME_MOTION_TYPE,
		COLOR_SCHEME_SLEEP_STATE,
		COLOR_SCHEME_ISLAND
	};

protected:
	// NOLINTNEXTLINE(readability-identifier-naming)
	static void _bind_methods();

public:
	JoltDebugGeometry3D();

	~JoltDebugGeometry3D() override;

	void _process(double p_delta) override;

	bool get_draw_bodies() const;

	void set_draw_bodies(bool p_enabled);

	bool get_draw_shapes() const;

	void set_draw_shapes(bool p_enabled);

	bool get_draw_constraints() const;

	void set_draw_constraints(bool p_enabled);

	bool get_draw_bounding_boxes() const;

	void set_draw_bounding_boxes(bool p_enabled);

	bool get_draw_centers_of_mass() const;

	void set_draw_centers_of_mass(bool p_enabled);

	bool get_draw_transforms() const;

	void set_draw_transforms(bool p_enabled);

	bool get_draw_velocities() const;

	void set_draw_velocities(bool p_enabled);

	bool get_draw_constraint_reference_frames() const;

	void set_draw_constraint_reference_frames(bool p_enabled);

	bool get_draw_constraint_limits() const;

	void set_draw_constraint_limits(bool p_enabled);

	bool get_draw_as_wireframe() const;

	void set_draw_as_wireframe(bool p_enabled);

	ColorScheme get_draw_with_color_scheme() const;

	void set_draw_with_color_scheme(ColorScheme p_color_scheme);

	bool get_material_depth_test() const;

	void set_material_depth_test(bool p_enabled);

private:
#ifdef JPH_DEBUG_RENDERER
	JoltDebugRenderer* debug_renderer = nullptr;

	RID mesh;

	Ref<StandardMaterial3D> default_material;

	JoltDebugRenderer::DrawSettings draw_settings;
#endif // JPH_DEBUG_RENDERER
};

VARIANT_ENUM_CAST(JoltDebugGeometry3D::ColorScheme);
