#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <list.h>

typedef struct MapItem {
    char *key;
    void *val;
    MapItem *next;
} MapItem;

typedef struct Map {
    MapItem** items;
    size_t size;
    size_t length;
} Map;


Map *mapInit(unsigned length);

void mapPut(Map *map, char *key, void *val, size_t len);

void *mapGet(Map *map, char *key);

void mapRemove(Map *map, char *key);

size_t hash_func(char *key);

void mapFree(Map *map);

void mapExpand(Map *map,  size_t length);

#endif
