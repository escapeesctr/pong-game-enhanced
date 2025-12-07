#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

class Game {
private:
	sf::RenderWindow window;
	
	sf::RectangleShape leftPaddle;
	sf::RectangleShape rightPaddle;

	sf::CircleShape ball;

	int leftScore;
	int rightScore;
	sf::Font font;
	sf::Text leftScoreText;
	sf::Text rightScoreText;
	sf::Text gameOverText;

	bool gameRunning;
	bool gameOver;

	float ballSpeedX;
	float ballSpeedY;
	float baseSpeed;

	sf::SoundBuffer paddleBuffer;
	sf::SoundBuffer scoreBuffer;
	sf::Sound paddleSound;
	sf::Sound scoreSound;

public:
	Game() : window(sf::VideoMode(800, 600), "Pong Game - Enhanced", sf::Style::Close),
		leftScore(0), rightScore(0),
		gameRunning(false), gameOver(false),
		ballSpeedX(5.0f), ballSpeedY(3.0f), baseSpeed(5.0f) {

		setupGame();
		loadSounds();
	}

	void setupGame() {
		leftPaddle.setSize(sf::Vector2f(20, 100));
		leftPaddle.setPosition(50, 250);
		leftPaddle.setFillColor(sf::Color::White);

		rightPaddle.setSize(sf::Vector2f(20, 100));
		rightPaddle.setPosition(730, 250);
		rightPaddle.setFillColor(sf::Color::White);

		ball.setRadius(10);
		ball.setPosition(400, 300);
		ball.setFillColor(sf::Color::Red);

		if (!font.loadFromFile("arial.ttf")) {
			std::cout << "Font not found, using default\n";
			font = sf::Font();
			if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {}
		}

		leftScoreText.setFont(font);
		leftScoreText.setCharacterSize(50);
		leftScoreText.setFillColor(sf::Color::White);
		leftScoreText.setPosition(200, 20);

		rightScoreText.setFont(font);
		rightScoreText.setCharacterSize(50);
		rightScoreText.setFillColor(sf::Color::White);
		rightScoreText.setPosition(600, 20);

		gameOverText.setFont(font);
		gameOverText.setCharacterSize(40);
		gameOverText.setFillColor(sf::Color::Yellow);
		gameOverText.setPosition(250, 250);
		gameOverText.setString("Game Over!\nPress R to restart\nPress ESC to exit");

		updateScoreText();

		window.setFramerateLimit(60);
	}

	void loadSounds() {
		std::cout << "Sound system initialized (add .wav files for real sounds\n";
	}

	void updateScoreText() {
		std::stringstream ssLeft, ssRight;
		ssLeft << leftScore;
		ssRight << rightScore;

		leftScoreText.setString(ssLeft.str());
		rightScoreText.setString(ssRight.str());
	}

	void resetBall() {
		ball.setPosition(400, 300);

		ballSpeedX = (rand() % 2 == 0) ? baseSpeed : -baseSpeed;
		ballSpeedY = (rand() % 2 == 0) ? 3.0f : -3.0f;
	}

	void increaseBallSpeed() {
		ballSpeedX *= 1.1f;
		ballSpeedY *= 1.1f;
	}

	void checkWinCondition() {
		if (leftScore >= 10) {
			gameOver = true;
			gameOverText.setString("Left Player Wins!\nPress R to restart\nPress ESC to exit");
		}
		else if (rightScore >= 10) {
			gameOver = true;
			gameOverText.setString("Right Player Wins!\nPress R to restart\nPress ESC to exit");
		}
	}

	void restartGame() {
		leftScore = 0;
		rightScore = 0;
		gameOver = false;
		ballSpeedX = baseSpeed;
		ballSpeedY = 3.0f;
		updateScoreText();
		resetBall();
	}

	void handleInput() {
		if (gameOver) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				restartGame();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gameRunning = true;
		}

		float paddleSpeed = 8.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftPaddle.getPosition().y > 0) {
			leftPaddle.move(0, -paddleSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftPaddle.getPosition().y < 500) {
			leftPaddle.move(0, paddleSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightPaddle.getPosition().y > 0) {
			rightPaddle.move(0, -paddleSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightPaddle.getPosition().y < 500) {
			rightPaddle.move(0, paddleSpeed);
		}
	}

	void update() {
		if (!gameRunning || gameOver) return;

		ball.move(ballSpeedX, ballSpeedY);

		if (ball.getPosition().y <= 0 || ball.getPosition().y >= 580) {
			ballSpeedY = -ballSpeedY;
		}

		if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds())) {
			ballSpeedX = abs(ballSpeedX);
			increaseBallSpeed();
		}
		
		if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds())) {
			ballSpeedX = -abs(ballSpeedX);
			increaseBallSpeed();
		}

		if (ball.getPosition().x <= 0) {
			rightScore++;
			updateScoreText();
			resetBall();
			checkWinCondition();
		}

		if (ball.getPosition().x >= 800) {
			leftScore++;
			updateScoreText();
			resetBall();
			checkWinCondition();
		}
	}

	void drawMenu() {
		sf::Text menuText;
		menuText.setFont(font);
		menuText.setCharacterSize(30);
		menuText.setFillColor(sf::Color::Cyan);
		menuText.setPosition(250, 200);
		menuText.setString("PONG GAME - ENHANCED\n\nControls:\nLeft: W/S\nRight: Up/Down\n\nPress SPACE to start\nPress ESC to exit");

		window.draw(menuText);
	}

	void render() {
		window.clear(sf::Color::Black);

		if (!gameRunning && !gameOver) {
			drawMenu();
		}
		else {
			for (int i = 0; i < 600; i += 40) {
				sf::RectangleShape line(sf::Vector2f(10, 20));
				line.setPosition(395, i);
				line.setFillColor(sf::Color::White);
				window.draw(line);
			}

			window.draw(leftPaddle);
			window.draw(rightPaddle);
			window.draw(ball);
			window.draw(leftScoreText);
			window.draw(rightScoreText);

			if (gameOver) {
				window.draw(gameOverText);
			}
		}

		window.display();
	}

	void run() {
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}

			handleInput();
			update();
			render();
		}
	}
};

int main() {
	std::cout << "=== PONG GAME - ENHANCED ===\n";
	std::cout << "Features:\n";
	std::cout << "- Score system (first to 10 points wins)\n";
	std::cout << "- Increasing ball speed\n";
	std::cout << "- Game over screen\n";
	std::cout << "- Restart functionality\n";
	std::cout << "- Menu screen\n\n";

	Game game;
	game.run();

	return 0;

}