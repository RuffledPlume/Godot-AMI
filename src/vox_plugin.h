#pragma once

#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/ref.hpp>

#include "vox_importer.h"

class VoxEditorPlugin : public godot::EditorPlugin
{
	GDCLASS(VoxEditorPlugin, godot::EditorPlugin)

public:
	void _notification(int p_what);
protected:
	static void _bind_methods();
private:
	godot::Ref<VoxImporter> m_Importer;
};