Bounds
	X		int
	Y		int
	Width	int
	Height	int

DockSettings
	Docked		bool
	Undocked	Bounds

EditorSettings
	DockBounds map[string]DockSettings
