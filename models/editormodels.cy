EditorDockSettings
	Docked   bool
	Visible  bool
	Undocked Bounds

EditorSettings
	DockBounds  map[string]EditorDockSettings
	OpenProject string
	OpenFiles   []string
	OpenTab     int
