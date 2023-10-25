#include "vox_importer.h"

#include "godot_cpp/variant/utility_functions.hpp"

int32_t VoxImporter::_get_import_order() const
{
	return 0;
}

double VoxImporter::_get_priority() const
{
	return 100;
}

int32_t VoxImporter::_get_preset_count() const
{
	return 0;
}

godot::String VoxImporter::_get_preset_name(int32_t preset_index) const
{
	return "";
}

godot::String VoxImporter::_get_importer_name() const
{
	return "Vox Importer";
}

godot::String VoxImporter::_get_visible_name() const
{
	return "Vox Importer";
}

godot::PackedStringArray VoxImporter::_get_recognized_extensions() const
{
	return godot::Array::make("vox");
}

godot::String VoxImporter::_get_resource_type() const
{
	return "Mesh";
}

godot::String VoxImporter::_get_save_extension() const
{
	return "tscn";
}

godot::Dictionary _make_import_option(godot::String name, godot::Variant default)
{
	godot::Dictionary result;
	result["name"] = name;
	result["default_value"] = default;
	return result;
}

godot::TypedArray<godot::Dictionary> VoxImporter::_get_import_options(const godot::String& path, int32_t preset_index) const
{
	godot::TypedArray<godot::Dictionary> options;
	options.push_back(_make_import_option("test", 0.0f));
	return options;
}

bool VoxImporter::_get_option_visibility(const godot::String& path, const godot::StringName& option_name, const godot::Dictionary& options) const
{
	return true;
}

godot::Error VoxImporter::_import(const godot::String& source_file, const godot::String& save_path, const godot::Dictionary& options, const godot::TypedArray<godot::String>& platform_variants, const godot::TypedArray<godot::String>& gen_files) const
{
	godot::UtilityFunctions::print("Vox Importing Path: ", source_file);
	return godot::Error::OK;
}

void VoxImporter::_bind_methods() {}