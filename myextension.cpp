// LuaSqlite.cpp
// Extension lib defines
#define LIB_NAME "LuaSqlite"
#define MODULE_NAME "luasqlite"

// include the Defold SDK
#include <dmsdk/sdk.h>

static int Reverse(lua_State* L)
{
    // The number of expected items to be on the Lua stack
    // once this struct goes out of scope
    DM_LUA_STACK_CHECK(L, 1);

    // Check and get parameter string from stack
    char* str = (char*)luaL_checkstring(L, 1);

    // Reverse the string
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        const char a = str[i];
        const char b = str[len - i - 1];
        str[i] = b;
        str[len - i - 1] = a;
    }

    // Put the reverse string on the stack
    lua_pushstring(L, str);

    // Return 1 item
    return 1;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
{
    {"reverse", Reverse},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeLuaSqlite(dmExtension::AppParams* params)
{
    dmLogInfo("AppInitializeLuaSqlite\n");
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeLuaSqlite(dmExtension::Params* params)
{
    // Init Lua
    LuaInit(params->m_L);
    dmLogInfo("Registered %s Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeLuaSqlite(dmExtension::AppParams* params)
{
    dmLogInfo("AppFinalizeLuaSqlite\n");
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeLuaSqlite(dmExtension::Params* params)
{
    dmLogInfo("FinalizeLuaSqlite\n");
    return dmExtension::RESULT_OK;
}

dmExtension::Result OnUpdateLuaSqlite(dmExtension::Params* params)
{
    dmLogInfo("OnUpdateLuaSqlite\n");
    return dmExtension::RESULT_OK;
}

void OnEventLuaSqlite(dmExtension::Params* params, const dmExtension::Event* event)
{
    switch(event->m_Event)
    {
        case dmExtension::EVENT_ID_ACTIVATEAPP:
            dmLogInfo("OnEventLuaSqlite - EVENT_ID_ACTIVATEAPP\n");
            break;
        case dmExtension::EVENT_ID_DEACTIVATEAPP:
            dmLogInfo("OnEventLuaSqlite - EVENT_ID_DEACTIVATEAPP\n");
            break;
        case dmExtension::EVENT_ID_ICONIFYAPP:
            dmLogInfo("OnEventLuaSqlite - EVENT_ID_ICONIFYAPP\n");
            break;
        case dmExtension::EVENT_ID_DEICONIFYAPP:
            dmLogInfo("OnEventLuaSqlite - EVENT_ID_DEICONIFYAPP\n");
            break;
        default:
            dmLogWarning("OnEventLuaSqlite - Unknown event id\n");
            break;
    }
}

// Defold SDK uses a macro for setting up extension entry points:
//
// DM_DECLARE_EXTENSION(symbol, name, app_init, app_final, init, update, on_event, final)

// LuaSqlite is the C++ symbol that holds all relevant extension data.
// It must match the name field in the `ext.manifest`
DM_DECLARE_EXTENSION(LuaSqlite, LIB_NAME, AppInitializeLuaSqlite, AppFinalizeLuaSqlite, InitializeLuaSqlite, OnUpdateLuaSqlite, OnEventLuaSqlite, FinalizeLuaSqlite)
