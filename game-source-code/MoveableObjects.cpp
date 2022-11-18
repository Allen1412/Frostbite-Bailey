#include "MoveableObjects.h"

void MoveableObjects::move(const Direction& _direction)
{
    switch(_direction) {
    case(Direction::Up):
        jump_up();
        break;
    case(Direction::Down):
        jump_down();
        break;
    case(Direction::Left):
        move_left();
        break;
    case(Direction::Right):
        move_right();
        break;
    default:
        return;
    }
}


void MoveableObjects::jump_up()
{

    changePosition(0, -getVerticalSpeed());
}


void MoveableObjects::jump_down()
{

    changePosition(0, getVerticalSpeed());

}

void MoveableObjects::move_left()
{
    changePosition(-getHorizontalSpeed(), 0);
}


void MoveableObjects::move_right()
{
    changePosition(getHorizontalSpeed(), 0);
}


void MoveableObjects::setHorizontalSpeed(const float& _speed)
{

    horizontal_speed = _speed * delta;
}

void MoveableObjects::setVerticalSpeed(const float& _speed)
{
    vertical_speed = _speed * delta;
}


void MoveableObjects::changePosition(const float& x_pos, const float& y_pos)
{
    position_.xCoord += x_pos;
    position_.yCoord += y_pos;
}

void MoveableObjects::setSize(const float& _xmin, const float& _ymin, const float& _xmax, const float& _ymax)
{
    size_.height_ = _ymax - _ymin;
    size_.width_ = _xmax - _xmin;
}


void MoveableObjects::setPosition(const float& x_pos, const float& y_pos)
{
    position_.xCoord = x_pos;
    position_.yCoord = y_pos;
}
