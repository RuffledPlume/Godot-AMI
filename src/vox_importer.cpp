#include "vox_importer.h"

#include "godot_cpp/variant/utility_functions.hpp"

godot::PackedStringArray VoxImporter::_get_extensions() const
{
	return godot::Array::make("vox");
}

godot::Object* VoxImporter::_import_scene(const godot::String& path, uint32_t flags, const godot::Dictionary& options)
{
	godot::UtilityFunctions::print("Vox Importing Path: ", path);
	return nullptr;
}

void VoxImporter::_bind_methods() {}