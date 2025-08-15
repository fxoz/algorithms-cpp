//
// Created by Felix on 2025-08-15.
//

#ifndef INFINITE_WALL_H
#define INFINITE_WALL_H
#include <complex>

// A thought experiment mentioned by my professor:
// Given an infinitely wide wall with a given door at *either* the left OR the right side
// (door is at a random location):
// What is the most efficient method of finding said door?

class InfiniteWallExperiment {
private:
    int _iterations = 0;
    int _door_location; // Can be anything, negative as well, preferably not a |low| number
    int _position = 0;
    int _distance_travelled = 0;
    int _is_door_found = false;
public:
    InfiniteWallExperiment(int door_location) : _door_location(door_location) {};

    void walkByRelativePos(int delta) {
        _iterations++;
        _position += delta;
        _distance_travelled += abs(delta);
        std::cout << "[" << _iterations << "] " <<
            "Walked by " << delta << "; we're now at " << _position <<
                " | dist. travelled=" << _distance_travelled << "\n";
        _is_door_found = (_door_location < 0 ? _position < _door_location : _position > _door_location);
        if (_is_door_found) {
            std::cout << "We found the door at " << _door_location << ". Please note the total distance we travelled of " << _distance_travelled << " units!\n";
        }
    }

    bool isDone() {
        return _is_door_found;
    }
};

// ---------- APPROACHES ----------

void naiveAlgo() {
    InfiniteWallExperiment ex{123};

    int delta = -1; // walk 1 "meter" left

    while (!ex.isDone()) {
        ex.walkByRelativePos(delta);

        delta *= -1; // switch direction
        (delta > 0 ? delta++ : delta--); // increase the abs(delta)
    }
}

void doubleAlgo() { // much more efficient
    InfiniteWallExperiment ex{123};

    int delta = -1; // walk 1 "meter" left

    while (!ex.isDone()) {
        ex.walkByRelativePos(delta);

        delta *= -2; // switch direction, double distance
    }
}

#endif //INFINITE_WALL_H
