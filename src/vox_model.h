#pragma once

#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/templates/vector.hpp>

class VoxModel : public godot::MeshInstance3D
{
	GDCLASS(VoxModel, godot::MeshInstance3D)

public:
	void set_voxels(godot::PackedByteArray Voxels);
	godot::PackedByteArray get_voxels() const;

	void set_palatte(godot::PackedInt32Array Palatte);
	godot::PackedInt32Array get_palatte() const;

	void set_size(godot::Vector3i Size);
	godot::Vector3i get_size();

	void set_voxel(int32_t x, int32_t y, int32_t z, int32_t palatte_idx);
	uint8_t get_voxel(int32_t x, int32_t y, int32_t z) const;

	void generate_mesh();
protected:
	static void _bind_methods();
public:
	godot::PackedByteArray Voxels;
	godot::PackedInt32Array Palatte;
	godot::Vector3i Size;
};