#pragma once

#include <godot_cpp/classes/editor_scene_format_importer.hpp>
#include <godot_cpp/core/class_db.hpp>

class VoxImporter : public godot::EditorSceneFormatImporter
{
	GDCLASS(VoxImporter, godot::EditorSceneFormatImporter)
public:
	godot::PackedStringArray _get_extensions() const override;
	godot::Object* _import_scene(const godot::String& path, uint32_t flags, const godot::Dictionary& options) override;
protected:
	static void _bind_methods();
};