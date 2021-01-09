# cappucino-example-mod
Example Cappucino Mod

# actually customizing the mod
to edit the created scene callback, edit `MyLayer::init` in `MyLayer.cpp`.
to edit the button callback, edit `hooks::MenuLayer::callback` in `hooks.cpp`.

# debugging your mod
to debug, open Geometry Dash, start debugging, and inject the DLL. if you have a default team installation of GD, it should work. if not, right click on the solution, go to debugging, and edit the "command" field to be the path to your GeometryDash.exe.
