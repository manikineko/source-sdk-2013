# SwarmForge

SwarmForge is a free modding platform built on Source SDK 2013, designed to provide a flexible foundation for creating custom games and mods with extensive modding capabilities.

## Overview

SwarmForge combines the best of multiple Source Engine games:
- **Alien Swarm** (free, required) - provides base game data and top-down gameplay mechanics
- **Half-Life 2** (optional) - additional assets and content
- **Team Fortress 2** (optional) - additional assets and content

## Features

### Current Features
- Multiplayer support based on HL2MP framework
- Team-based gameplay
- Custom player class system
- HUD elements (chat, target ID, team display, death notices)
- Scoreboard system
- Extensible architecture for future modding APIs

### Planned Features
- **Lua Modding API** - Script game logic using Lua (similar to GMod)
- **HTML GUI Extension** - Extend the UI using HTML/CSS/JavaScript
- **Multi-language Scripting Support** - Support for additional scripting languages
- **Top-down View Mode** - Optional top-down camera mode from Alien Swarm
- **Code Merging** - Integration of HL2 and TF2 codebases
- **Custom Entity System** - Extensible entity framework for mods

## Building SwarmForge

### Prerequisites
- Source SDK 2013 Multiplayer installed via Steam
- podman (for Linux builds)
- Python 3.13 or later

### Linux Build Instructions

1. Navigate to the `src` directory:
```bash
cd /path/to/source-sdk-2013/src
```

2. Run the SwarmForge build script:
```bash
./build_swarmforge [debug|release]
```

This will:
- Generate the build configuration using VPC
- Build all SwarmForge projects
- Create the necessary binaries

### Windows Build Instructions

1. Navigate to the `src` directory
2. Run VPC with SwarmForge configuration:
```bat
devtools\bin\vpc /swarmforge /windows /define:SOURCESDK +everything /mksln everything_swarmforge
```
3. Open the generated solution in Visual Studio 2022
4. Build the solution

## Running SwarmForge

### Linux
```bash
cd /path/to/source-sdk-2013/game
./mod_swarmforge_linux64
```

### Windows
Select the `Launcher Main (Mod SwarmForge)` project as the startup project and run it.

## Game Directory Structure

```
game/mod_swarmforge/
├── bin/              # Compiled binaries
├── cfg/              # Configuration files
├── maps/             # Custom maps
├── materials/        # Custom materials
├── resource/         # UI resources and localization
├── scripts/          # Game scripts
├── shaders/          # Custom shaders
├── custom/           # User mods and VPKs
├── download/         # Downloaded server content
├── gameinfo.txt      # Game configuration
└── steam.inf         # Steam metadata
```

## Asset Mounting

SwarmForge mounts content from multiple sources:

### Required
- **Alien Swarm (AppID 630)** - Free, provides base game data

### Optional
- **Half-Life 2 (AppID 220)** - Additional assets
- **Source SDK HL2 (AppID 243750)** - Basic HL2 content included with SDK

To enable optional mounts, uncomment the relevant sections in `game/mod_swarmforge/gameinfo.txt`.

## Modding API (Planned)

### Lua Integration
SwarmForge will include a Lua scripting engine similar to GMod, allowing:
- Custom game rules
- Entity manipulation
- HUD customization
- Server-side and client-side scripting

### HTML GUI
The HTML GUI system will allow:
- Custom UI panels using HTML/CSS/JavaScript
- Real-time web integration
- Modern web technologies for mod interfaces

## Development Roadmap

### Phase 1: Foundation (Current)
- [x] Basic game structure
- [x] Build system
- [x] Asset mounting configuration
- [x] Player and game rules system
- [ ] Basic gameplay testing

### Phase 2: Modding API
- [ ] Lua integration
- [ ] Script binding system
- [ ] API documentation
- [ ] Example mods

### Phase 3: GUI System
- [ ] HTML rendering engine
- [ ] GUI extension API
- [ ] Developer tools

### Phase 4: Advanced Features
- [ ] Top-down camera mode
- [ ] HL2/TF2 code merge
- [ ] Custom entity system
- [ ] Networking optimizations

## Contributing

SwarmForge is an open project. To contribute:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## License

SwarmForge is licensed under the SOURCE 1 SDK LICENSE, same as the Source SDK 2013.

## Credits

- Valve Software - Source Engine and Source SDK 2013
- Alien Swarm team - Alien Swarm game data
- Community contributors

## Support

For issues, questions, or discussions:
- GitHub Issues: https://github.com/manikineko/source-sdk-2013/issues
- Documentation: See inline code comments and this README

## Acknowledgments

This project builds upon the excellent work of:
- Valve Software and the Source Engine team
- The Alien Swarm development team
- The Source SDK 2013 community
- Garry's Mod for Lua scripting inspiration
