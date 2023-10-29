#include "vox_model.h"

#include "godot_cpp/classes/ref.hpp"
#include "godot_cpp/classes/surface_tool.hpp"
#include "godot_cpp/classes/box_mesh.hpp"

void VoxModel::set_voxels(godot::PackedByteArray Voxels)
{
	this->Voxels = Voxels;
}

godot::PackedByteArray VoxModel::get_voxels() const
{
	return Voxels;
}

void VoxModel::set_palatte(godot::PackedInt32Array Palatte)
{
	this->Palatte = Palatte;
}

godot::PackedInt32Array VoxModel::get_palatte() const
{
	return Palatte;
}

void VoxModel::set_size(godot::Vector3i Size)
{
	this->Size = Size;
}

godot::Vector3i VoxModel::get_size()
{
	return Size;
}

void VoxModel::set_voxel(int32_t x, int32_t y, int32_t z, int32_t palatte_idx)
{
	Voxels[x + Size.x * (y + Size.z * z)] = palatte_idx;
}

uint8_t VoxModel::get_voxel(int32_t x, int32_t y, int32_t z) const
{
	return Voxels[x + Size.x * (y + Size.z * z)];
}

void VoxModel::generate_mesh()
{
	//TODO: Implement some algo to reduce verticies & faces. For now just use a box mesh

	godot::Ref<godot::BoxMesh> BoxMesh;
	BoxMesh.instantiate();

	godot::PackedVector3Array CubeFaces = BoxMesh->get_faces();

	godot::Ref<godot::SurfaceTool> st;
	st.instantiate();
	st->begin(godot::Mesh::PRIMITIVE_TRIANGLES);

	int32_t idx = 0;
	for (int32_t x = 0; x < Size.x; x++)
	{
		for (int32_t y = 0; y < Size.y; y++)
		{
			for (int32_t z = 0; z < Size.z; z++, idx++)
			{
				if (Voxels[idx] != 0)
				{
					//Voxel is here
					godot::Vector3 VoxelPos(x, y, z);
					for (int32_t v = 0; v < CubeFaces.size(); v++)
					{
						st->add_vertex(CubeFaces[v] + VoxelPos);
					}
				}
			}
		}
	}
	st->index();
	st->generate_normals();
	set_mesh(st->commit());
}

void VoxModel::_bind_methods() 
{
	godot::ClassDB::bind_method(godot::D_METHOD("set_voxels", "voxels"), &VoxModel::set_voxels);
	godot::ClassDB::bind_method(godot::D_METHOD("get_voxels"), &VoxModel::get_voxels);
	
	godot::ClassDB::bind_method(godot::D_METHOD("set_palatte", "palatte"), &VoxModel::set_palatte);
	godot::ClassDB::bind_method(godot::D_METHOD("get_palatte"), &VoxModel::get_palatte);
	
	godot::ClassDB::bind_method(godot::D_METHOD("set_size", "size"), &VoxModel::set_size);
	godot::ClassDB::bind_method(godot::D_METHOD("get_size"), &VoxModel::get_size);
	
	godot::ClassDB::bind_method(godot::D_METHOD("set_voxel", "x", "y", "z", "palatte_idx"), &VoxModel::set_voxel);
	godot::ClassDB::bind_method(godot::D_METHOD("get_voxel", "x", "y", "z"), &VoxModel::get_voxel);
	
	godot::ClassDB::bind_method(godot::D_METHOD("generate_mesh"), &VoxModel::generate_mesh);
	
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::ARRAY, "voxels"), "get_voxels", "set_voxels");
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::ARRAY, "palatte"), "get_palatte", "set_palatte");
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::ARRAY, "size"), "get_size", "set_size");
}