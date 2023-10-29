#pragma once

#include <godot_cpp/classes/editor_scene_format_importer.hpp>
#include <godot_cpp/core/class_db.hpp>

class VoxImporter : public godot::EditorSceneFormatImporter
{
	GDCLASS(VoxImporter, godot::EditorSceneFormatImporter)
public:
	virtual uint32_t _get_import_flags() const override;
	virtual godot::PackedStringArray _get_extensions() const override;
	virtual Object* _import_scene(const godot::String& path, uint32_t flags, const godot::Dictionary& options) override;
	virtual void _get_import_options(const godot::String& path) override;
	virtual godot::Variant _get_option_visibility(const godot::String& path, bool for_animation, const godot::String& option) const override;
protected:
	static void _bind_methods();
};