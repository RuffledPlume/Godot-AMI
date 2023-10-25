#pragma once

#include <godot_cpp/classes/editor_import_plugin.hpp>
#include <godot_cpp/core/class_db.hpp>

class VoxImporter : public godot::EditorImportPlugin
{
	GDCLASS(VoxImporter, godot::EditorImportPlugin)
public:
	int32_t _get_import_order() const override;
	double _get_priority() const override;
	int32_t _get_preset_count() const override;
	godot::String _get_preset_name(int32_t preset_index) const override;
	godot::String _get_importer_name() const override;
	godot::String _get_visible_name() const;
	godot::PackedStringArray _get_recognized_extensions() const override;
	godot::String _get_save_extension() const override;
	godot::String _get_resource_type() const override;
	godot::TypedArray<godot::Dictionary> _get_import_options(const godot::String& path, int32_t preset_index) const;
	bool _get_option_visibility(const godot::String& path, const godot::StringName& option_name, const godot::Dictionary& options) const;
	godot::Error _import(const godot::String& source_file, const godot::String& save_path, const godot::Dictionary& options, const godot::TypedArray<godot::String>& platform_variants, const godot::TypedArray<godot::String>& gen_files) const override;
protected:
	static void _bind_methods();
};