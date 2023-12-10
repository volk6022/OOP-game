#pragma once
class I_Visualise
{
public:
    virtual void printField() = 0;

    virtual void GameOver(int steps) = 0;

    virtual void Win(int steps) = 0;
};

