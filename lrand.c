#include <math.h>

#include "lua.h"
#include "lauxlib.h"

#define MYNAME "lrand"
#define MYVERSION	MYNAME " library for " LUA_VERSION
#define MYTYPE MYNAME "_state"
#define SEED 1794ULL

#include "mt19937-64.c"

static MT *Pget(lua_State *L, int i) {
    return luaL_checkudata(L, i, MYTYPE);
}

static MT *Pnew(lua_State *L) {
    MT *c= lua_newuserdata(L, sizeof(MT));
    luaL_getmetatable(L, MYTYPE);
    lua_setmetatable(L, -2);
    return c;
}

//new([seed])
static int Lnew(lua_State *L) {
    lua_Integer seed = luaL_optinteger(L, 1, SEED);
    MT *c = Pnew(L);
    init_genrand64(c, seed);
    return 1;
}

//clone(c)
static int Lclone(lua_State *L) {
    MT *c=Pget(L,1);
    MT *d=Pnew(L);
    *d=*c;
    return 1;
}

static int Lseed(lua_State *L) {
    MT *c = Pget(L,1);
    init_genrand64(c,luaL_optinteger(L,2,SEED));
    lua_settop(L,1);
    return 1;
}

static int Lrandu64(lua_State *L) {
    MT *c = Pget(L, 1);
    lua_pushinteger(L, genrand64_int64(c));
    return 1;
}

static int Lrandi64(lua_State *L) {
    MT *c = Pget(L, 1);
    lua_pushinteger(L, genrand64_int63(c));
    return 1;
}

static int Lrandd(lua_State *L) {
    MT *c = Pget(L, 1);
    lua_pushnumber(L, genrand64_real1(c));
    return 1;
}

static int Ltostring(lua_State *L)
{
    MT *c=Pget(L,1);
    lua_pushfstring(L,"%s %p",MYTYPE,(void*)c);
    return 1;
}

static const luaL_Reg R[] = {
    {"__tostring", Ltostring},
    {"clone", Lclone},
    {"new", Lnew},
    {"seed", Lseed},
    {"randu64", Lrandu64},
    {"randi64", Lrandi64},
    {"randd", Lrandd},
    {NULL, NULL}
};

LUALIB_API int luaopen_lrand(lua_State *L) {
    luaL_newmetatable(L,MYTYPE);
    luaL_setfuncs(L, R, 0);
    lua_pushliteral(L,"version");			/** version */
    lua_pushliteral(L,MYVERSION);
    lua_settable(L,-3);
    lua_pushliteral(L,"__index");
    lua_pushvalue(L,-2);
    lua_settable(L,-3);
    lua_pushliteral(L,"__call");			/** __call(c) */
    lua_pushliteral(L,"randu64");
    lua_gettable(L,-3);
    lua_settable(L,-3);

    return 1;
}