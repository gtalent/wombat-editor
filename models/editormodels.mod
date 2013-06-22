Bounds
	X		int
	Y		int
	Width	int
	Height	int

DockSettings
	Docked		bool
	Undocked	Bounds

SaveVariables
	Vars map[string]unknown

EditorSettings
	DockBounds map[string]DockSettings
