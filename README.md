# Pong Game Enhanced - C++ with SFML

An enhanced version of the classic Pong game with scoring system, difficulty progression, and complete game states.

## 🎮 Enhanced Features
- **Scoring System**: First to 10 points wins
- **Progressive Difficulty**: Ball speed increases by 10% with each hit
- **Complete Game Flow**: Menu → Gameplay → Game Over → Restart
- **Smooth Controls**: Responsive paddle movement
- **Visual Feedback**: Score display, center line, game states

## 🕹️ Game States
1. **MENU SCREEN**: Instructions and controls
2. **GAMEPLAY**: Active game with scoring
3. **GAME OVER**: Winner announcement with restart options

## 🎯 Controls
- **Left Paddle**: W (up), S (down)
- **Right Paddle**: ↑ (up), ↓ (down)
- **Start Game**: SPACE
- **Restart**: R
- **Exit**: ESC

## 🛠️ Technical Implementation
### Game Architecture
- Object-Oriented Design with `Game` class
- State management (menu, gameplay, game over)
- Event-driven input handling
- Frame-rate independent movement

### SFML Features Used
- `sf::RenderWindow` for display management
- `sf::RectangleShape` and `sf::CircleShape` for game objects
- `sf::Font` and `sf::Text` for UI elements
- `sf::Keyboard` for input handling

### Game Mechanics
- Collision detection with paddle and walls
- Dynamic ball speed calculation
- Score tracking and win condition checking
- Random ball direction on reset

## 📊 Code Structure
Game Class
├── Constructor: Initializes game state
├── setupGame(): Configures game objects
├── handleInput(): Processes keyboard input
├── update(): Game logic and physics
├── render(): Drawing and display
└── run(): Main game loop

## 🔧 Build Instructions
1. Install SFML and set include/library paths
2. Build with Visual Studio (x64, Debug)
3. Copy SFML DLLs to executable directory
4. Ensure `arial.ttf` is available or modify font loading

## 🎨 Visual Design
- Clean black background with white game objects
- Cyan menu text for high visibility
- Yellow game over messages
- Center line for visual reference

## 🚀 What I Learned
- Advanced game state management
- Progressive difficulty implementation
- SFML text rendering and font handling
- Complete game lifecycle implementation
- User interface design for games

## 📈 Future Improvements
- Add sound effects and background music
- Implement power-ups or special abilities
- Add player names and high score tracking
- Network multiplayer support
- Visual effects for ball collisions

## 🎯 Real-World Applications
- Understanding game development pipelines
- Learning collision detection algorithms
- Practicing state machine design
- Building complete, polished applications

## 🔗 Connect
- **Portfolio**: [https://escapeesctr.github.io/my-portfolio/](https://escapeesctr.github.io/my-portfolio/)
- **LinkedIn**: [https://www.linkedin.com/in/melihenesaktas/](https://www.linkedin.com/in/melihenesaktas/)
- **GitHub**: [@escapeesctr](https://github.com/escapeesctr)
