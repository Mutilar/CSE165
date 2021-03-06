#include "DrawTool.h"
#include <iostream>

DrawTool::DrawTool()
{
    ghost_line = new Line();
    erasing = false;
}
void DrawTool::draw(std::vector<Line *> lines, Point *camera_position)
{
    ghost_line->draw(camera_position);
    for (std::vector<Line *>::iterator it = lines.begin(); it != lines.end(); ++it)
    {
        Line *temp_line = *it;
        temp_line->draw(camera_position);
    }
}
void DrawTool::drag(int x, int y, Point *camera_position)
{
    ghost_line->setEndPoint(x - camera_position->getX(), y - camera_position->getY());
}
void DrawTool::setState(std::vector<Line *> &lines, bool state, int x, int y, Point *camera_position)
{
    this->state = state;
    if (state == true)
    {
        ghost_line->setStartPoint(x - camera_position->getX(), y - camera_position->getY());
    }
    else
    {
        if (erasing)
        {
            for (std::vector<Line *>::iterator it = lines.begin(); it != lines.end(); ++it)
            {
                Line *line = *it;

                float denominator = ((ghost_line->getEndPoint()->getX() - ghost_line->getStartPoint()->getX()) * (line->getEndPoint()->getY() - line->getStartPoint()->getY())) - ((ghost_line->getEndPoint()->getY() - ghost_line->getStartPoint()->getY()) * (line->getEndPoint()->getX() - line->getStartPoint()->getX()));
                float numerator1 = ((ghost_line->getStartPoint()->getY() - line->getStartPoint()->getY()) * (line->getEndPoint()->getX() - line->getStartPoint()->getX())) - ((ghost_line->getStartPoint()->getX() - line->getStartPoint()->getX()) * (line->getEndPoint()->getY() - line->getStartPoint()->getY()));
                float numerator2 = ((ghost_line->getStartPoint()->getY() - line->getStartPoint()->getY()) * (ghost_line->getEndPoint()->getX() - ghost_line->getStartPoint()->getX())) - ((ghost_line->getStartPoint()->getX() - line->getStartPoint()->getX()) * (ghost_line->getEndPoint()->getY() - ghost_line->getStartPoint()->getY()));

                if (denominator == 0)
                    if (numerator1 == 0 && numerator2 == 0)
                    {
                        lines.erase(it);
                    }

                float r = numerator1 / denominator;
                float s = numerator2 / denominator;

                if ((r >= 0 && r <= 1) && (s >= 0 && s <= 1))
                {
                    lines.erase(it);
                }
            }
        }
        else
            lines.push_back(new Line(ghost_line->getStartPoint()->getX(), ghost_line->getStartPoint()->getY(), ghost_line->getEndPoint()->getX(), ghost_line->getEndPoint()->getY()));
    }
}
