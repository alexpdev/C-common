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

Map *MapInit(unsigned length);
void MapPut(Map *map, char *key, void *val, size_t len);
void *MapGet(Map *map, char *key);
void MapRemove(Map *map, char *key);
size_t hash_func(char *key);
void MapFree(Map *map);
void MapExpand(Map *map, size_t length);

#endif
