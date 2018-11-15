#ifndef INCLUDE_APOINT_H_
#define INCLUDE_APOINT_H_

#include <iostream>
#include <map>
#include <memory>
#include <exception>
#include <functional>

using namespace std;

enum PType {
    EXIST,
    FIRE,
    BURN
};
class Coordinates {
    public:
    Coordinates(unsigned int x,unsigned int y) {
        this->x = x;
        this->y = y;
    }
    Coordinates(unsigned int x) {
        this->x = x;
        this->y = 0;
    }
    unsigned int x;
    unsigned int y;
    bool operator< (const Coordinates& rhs) const {
    return (this->x<rhs.x) || ((this->x==rhs.x) && (this->y < rhs.y));
    }
};

class Tree {
    public:
    Tree() {
        type = EXIST;
    }
    Tree(PType status) {
        this->type = status;
    }
    PType getType() {return this->type;}
    Tree operator++(int) {
        Tree temp = *this;
        switch(this->type) {
            case EXIST:
                this->type = FIRE;
            break;
            case FIRE:
                this->type = BURN;
            break;
            case BURN:
            break;
        }
        return temp;
    }
    private:
    PType type;
};
class SingleCell {
    public:
    SingleCell(int x,shared_ptr<map<Coordinates,Tree>> mp) {
        fullmap = mp;
        this->x = x;
    }
    Tree* operator[](int y) {
        if((*fullmap).find(Coordinates(x,y))==(*fullmap).end()) return nullptr;
        Tree* toReturn = &(*fullmap)[Coordinates(x,y)];
        return toReturn;
    }
    private:
    int x;
    shared_ptr<map<Coordinates,Tree>> fullmap;
};
class ForestMap {
    public:
    ForestMap() {
        fullMap = make_shared<map<Coordinates,Tree>>();
    }
    SingleCell operator[](int x) {
        return SingleCell(x,fullMap);
    }
    void add(int x,int y,PType status) {
        Tree new_tree(status);
        (*fullMap)[Coordinates(x,y)] = new_tree;
    }
    void drawAll(function<void(int,int,PType)> func) {
        map<Coordinates,Tree>& mp = *fullMap.get();
        map<Coordinates,Tree>::iterator it;
        for(it = mp.begin();it!=mp.end();it++) {
            func(it->first.x,it->first.y,it->second.getType());
        }
    }
    private:
    shared_ptr<map<Coordinates,Tree>> fullMap;
};
#endif
