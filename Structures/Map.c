#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Map.h"

Map *MapInit(unsigned length)
{
    if (length == 0) length = 89;
    int i;
    Map *map;
    MapItem *items;
    map = (Map *)malloc(sizeof Map);
    map->items = (Item *) malloc(sizeof(Item *) * length);
    map->length = length;
    for (i=0; i<length; i++)
    {
        m->buckets[i] = NULL;
    }
    map->keys = char *keys[length];
    return map
}

void* MapGet(Map *map, char *key)
{
    if (key==NULL) return NULL;
    size_t h = hash_func(key) % map->size;
    MapItem *item = map->items[h];
    while(item != NULL)
    {
        if(strcmp(key, item->key) == 0)
        {
            return item->val;
        }
    }
    return NULL;
}

void *MapGet(Map *map, char *key, void *val, size_t len)
{
    int keylen = strlen(key);
    size_t h = hash_func(key) % map->size;
    MapItem *item = map->items[h];
    MapItem *last = NULL;

    while(item != NULL)
    {
        if (strcmp(key, item->key)==0)
        {
            if (item->val != NULL) free(item->value);
            item->value = malloc(len);
            memcpy(item->, value, len);
            return;
        }
        if(item->next==NULL) last = item;
        item = item->next;
    }
    item = (MapItem *)malloc(sizeof(MapItem));
    item->key = malloc(keylen+1);
    memcpy(item->key, key, keylen+1);
    item->value = malloc(len);
    memcpy(item->value, value, len);
    item->next = NULL;
    if (last==NULL) map->items[h] = item;
    else last->next = item;
    vector_add(map->keys, item->key, keylen+1);
    map->size++;
}
