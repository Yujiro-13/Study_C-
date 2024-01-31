#include <fstream>
#include <iostream>

#define MAZESIZE_X 32
#define MAZESIZE_Y 32

struct t_wall
{
    bool north;
    bool east;
    bool south;
    bool west;
};

struct t_map
{
    t_wall wall[MAZESIZE_X][MAZESIZE_Y] = {0};
};

const char* MAP_FILE_PATH = "map.txt";

void map_write(t_map *map)
{
    std::ofstream ofile(MAP_FILE_PATH, std::ios::out);
    if (ofile.fail())
    {
        std::cerr << "Failed to open " << MAP_FILE_PATH << " for writing" << std::endl;
        return;
    }

    for (int i = 0; i < MAZESIZE_X; i++)
    {
        for (int j = 0; j < MAZESIZE_Y; j++)
        {
            ofile << map->wall[i][j].north << " ";
            ofile << map->wall[i][j].east << " ";
            ofile << map->wall[i][j].south << " ";
            ofile << map->wall[i][j].west << " ";
        }
        ofile << std::endl;
    }

    ofile.close();
}

void map_read(t_map *map)
{
    std::ifstream ifile(MAP_FILE_PATH, std::ios::in);
    if (ifile.fail())
    {
        std::cerr << "Failed to open " << MAP_FILE_PATH << " for reading" << std::endl;
        return;
    }

    for (int i = 0; i < MAZESIZE_X; i++)
    {
        for (int j = 0; j < MAZESIZE_Y; j++)
        {
            ifile >> map->wall[i][j].north;
            ifile >> map->wall[i][j].east;
            ifile >> map->wall[i][j].south;
            ifile >> map->wall[i][j].west;
        }
    }

    ifile.close();

    std::cout << "map->wall[0][0].north: " << map->wall[0][0].north << std::endl;
    std::cout << "map->wall[0][0].east: " << map->wall[0][0].east << std::endl;
    std::cout << "map->wall[0][0].south: " << map->wall[0][0].south << std::endl;
    std::cout << "map->wall[0][0].west: " << map->wall[0][0].west << std::endl;
    std::cout << "map->wall[11][26].north: " << map->wall[11][26].north << std::endl;
    std::cout << "map->wall[14][18].east: " << map->wall[14][18].east << std::endl;
    std::cout << "map->wall[4][31].south: " << map->wall[4][31].south << std::endl;
    std::cout << "map->wall[25][8].west: " << map->wall[25][8].west << std::endl;
}

int main()
{
    t_map myMap;

    myMap.wall[0][0].north = false;
    myMap.wall[0][0].east = true;
    myMap.wall[0][0].south = true;
    myMap.wall[0][0].west = true;
    myMap.wall[11][26].north = true;
    myMap.wall[14][18].east = true;
    myMap.wall[4][31].south = true;
    myMap.wall[25][8].west = true;

    map_write(&myMap);
    map_read(&myMap);

    // Now, 'myMap' contains the data read from the file.

    return 0;
}
