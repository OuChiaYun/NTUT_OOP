#include "../src/cookie.h"

/* The function help you to create the empty grid. */
/* You can use this function or create by yourself. */
bool** create_grid(){
    bool** array = new bool*[10];
    for(int i = 0; i < 10; i++){
        array[i] = new bool[10];
        for(int j = 0; j < 10; j++){
            array[i][j] = false;
        }
    }
    array[9][0] = true;
    return array;
}

/* The function help you to delete the grid. */
/* You should implement this by yourself. */
void delete_grid(bool** array){
    for( int i=0;i<10;++i ){
		    delete [] array[i];
    }
	delete [] array;
}

/* Add some test in here. */


TEST(Cookie,out_of_grid_range_4){

    bool** grid = create_grid();
    
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);


    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);

    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);


    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    // placeTop(grid);
    ASSERT_THROW(placeRight(grid),std::string);
    delete_grid(grid);


}


TEST(Cookie, regular_situation_1){

    bool** grid = create_grid();

    //ASSERT_THROW(placeTop(create_grid()),std::string);

    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);


    ASSERT_EQ(calcRow(grid, 8),2);
    ASSERT_EQ(calcColumn(grid, 7),0);
    delete_grid(grid);

}


TEST(Cookie, regular_situation_2){

    bool** grid = create_grid();

    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);

    ASSERT_EQ(calcColumn(grid, 0),3);
    delete_grid(grid);

}


TEST(Cookie,out_of_grid_range_1){

    bool** grid = create_grid();

    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeRight(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);

    // placeTop(grid);
    ASSERT_THROW(placeTop(grid),std::string);
    delete_grid(grid);

}


TEST(Cookie,out_of_grid_range_2){

    bool** grid = create_grid();


    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);


    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    // placeTop(grid);
    ASSERT_THROW(placeRight(grid),std::string);
    delete_grid(grid);


}


TEST(Cookie,column_or_row_is_out_of_grid_range_1){

    bool** grid = create_grid();

    placeRight(grid);
    placeRight(grid);

    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);

    // placeTop(grid);
    
    ASSERT_EQ(calcColumn(grid, 48755),-1);
    delete_grid(grid);

}



TEST(Cookie,column_or_row_is_out_of_grid_range_2){

    bool** grid = create_grid();

    placeRight(grid);
    placeRight(grid);

    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeRight(grid);

    placeTop(grid);
    placeTop(grid);

    // placeTop(grid);
    
    ASSERT_EQ(calcRow(grid, -10),-1);
    delete_grid(grid);

}


TEST(Cookie,out_of_grid_range_3){

    bool** grid = create_grid();
    
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);


    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);

    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);


    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    // placeTop(grid);
    ASSERT_THROW(placeRight(grid),std::string);
    delete_grid(grid);


}



TEST(Cookie,over_10_time_and_calc){

    bool** grid = create_grid();

    placeRight(grid);
    placeRight(grid);

    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeRight(grid);

    placeTop(grid);
    placeTop(grid);

    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeRight(grid);


    // placeTop(grid);
    
    ASSERT_EQ(calcRow(grid, 3),3);
    ASSERT_EQ(calcColumn(grid, 4),5);
    ASSERT_EQ(calcColumn(grid, 6),1);
    delete_grid(grid);

}

