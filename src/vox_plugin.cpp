#include "vox_plugin.h"

void VoxEditorPlugin::_notification(int p_what)
{
	if (p_what == godot::Node::NOTIFICATION_ENTER_TREE)
	{
		m_Importer.instantiate();
		add_scene_format_importer_plugin(m_Importer, true);
	}
	else if (p_what == godot::Node::NOTIFICATION_EXIT_TREE)
	{
		remove_scene_format_importer_plugin(m_Importer);
		m_Importer.unref();
	}
}

void VoxEditorPlugin::_bind_methods() {}