EditorDockSettings
	Docked   bool
	Visible  bool
	Undocked Bounds

EditorSettings
	DockBounds  map[string]EditorDockSettings
	OpenProject string
	OpenFiles   []string
	OpenTab     int

EditorProfile
	FileType       string
	PathStartsWith []string
	DefaultPaths   []string
	Editor         string # path the qml file
	NewFileMenu    string # path the qml file

EditorModule
	Profiles []EditorProfile
