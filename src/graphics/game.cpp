#include <graphics/game.h>

Game::Game()
  : raycaster_(glm::vec2(0, 0), 480, 1, 480){
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void Game::draw() {
  //setup environment
  Room room = Room();

  std::ifstream room_map("C:\\Users\\buddi\\Cinder\\my-projects\\final-project-vinsunkavalli\\resources\\testroom", std::ios::in);
  room_map >> room;

  Player player (4, 4, 0);

  //render background
  ci::gl::color(ci::Color("black"));
  ci::gl::clear();

  //render map - call raycast
  raycaster_.Raycast(room, player);
  //TODO render player model and gui
}
/*
void Game::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RETURN:
    {
      // ask your classifier to classify the image that's currently drawn on the
      // sketchpad and update current_prediction_
      NaiveBayesData dataset = NaiveBayesData();
      string image = sketchpad_.getCanvas();
      std::stringstream image_stream = std::stringstream(image);
      image_stream >> dataset;
      NaiveBayesModel model = NaiveBayesModel(dataset, weight_path_);
      current_prediction_ =
          model.runPrediction(dataset)[0];  // this will always be one length so getting first element
      break;
    }
    case ci::app::KeyEvent::KEY_DELETE:
      sketchpad_.Clear();
      break;
  }
}*/