# cappucino-example-mod
Example [Cappucino](https://github.com/andrenih/cappuccinoSDK/) Mod

# actually customizing the mod
to edit the button callback or created scene, edit `hooks::MenuLayer::callback` in `hooks.cpp`.
to edit the example layer, edit `MyLayer::init` in `MyLayer.cpp`, or add member variables / functions in `MyLayer/MyLayer.h`.

# debugging your mod
to debug, compile the solution, open Geometry Dash, start debugging, and inject the newly compiled DLL. if you have a default steam installation of GD, it should work. if not, right click on the solution, go to debugging, and edit the "command" field to be the path to your GeometryDash.exe.
