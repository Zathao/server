

#ifndef __TILE_H__
#define __TILE_H__


#include "item.h"


class Creature;


typedef std::vector<Item*> ItemVector;
typedef std::vector<Creature*> CreatureVector;


class Tile
{
public:
  Creature* getCreature(){
    return creatures[0];
  }

  Tile()
  {
    pz               = false;
    splash           = NULL;
    decaySplashAfter = 0;
  }

  Item           ground;
  Item*          splash;
  ItemVector     topItems;
  CreatureVector creatures;
  ItemVector     downItems;

  __int64        decaySplashAfter;

  bool removeThing(Thing *thing);
  void addThing(Thing *thing);

  int getCreatureStackPos(Creature *c);
  int getThingStackPos(Thing *thing);
	int getThingCount();

  Thing* getThingByStackPos(int pos);

  bool isBlocking();

  bool isPz();
  void setPz();
  
  std::string getDescription();
protected:
  bool pz;
};


#endif // #ifndef __TILE_H__

