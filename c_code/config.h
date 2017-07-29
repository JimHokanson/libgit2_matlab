#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/config

void config_add_backend(MEX_DEF_INPUT){
    //1
}

void config_add_file_ondisk(MEX_DEF_INPUT){
    //2
}

void config_backend_foreach_match(MEX_DEF_INPUT){
    //3
}

void config_delete_entry(MEX_DEF_INPUT){
    //4
}

void config_delete_multivar(MEX_DEF_INPUT){
    //5
}

void config_entry_free(MEX_DEF_INPUT){
    //6
}

void config_find_global(MEX_DEF_INPUT){
    //7
}

void config_find_programdata(MEX_DEF_INPUT){
    //8
}

void config_find_system(MEX_DEF_INPUT){
    //9
}

void config_find_xdg(MEX_DEF_INPUT){
    //10
}

void config_foreach(MEX_DEF_INPUT){
    //11
}

void config_foreach_match(MEX_DEF_INPUT){
    //12
}

void config_free(MEX_DEF_INPUT){
    //13
}

void config_get_bool(MEX_DEF_INPUT){
    //14
}

void config_get_entry(MEX_DEF_INPUT){
    //15
}

void config_get_int32(MEX_DEF_INPUT){
    //16
}

void config_get_int64(MEX_DEF_INPUT){
    //17
}

void config_get_mapped(MEX_DEF_INPUT){
    //18
}

void config_get_multivar_foreach(MEX_DEF_INPUT){
    //19
}

void config_get_path(MEX_DEF_INPUT){
    //20
}

void config_get_string(MEX_DEF_INPUT){
    //21
}

void config_get_string_buf(MEX_DEF_INPUT){
    //22
}

void config_init_backend(MEX_DEF_INPUT){
    //23
}

void config_iterator_free(MEX_DEF_INPUT){
    //24
}

void config_iterator_glob_new(MEX_DEF_INPUT){
    //25
}

void config_iterator_new(MEX_DEF_INPUT){
    //26
}

void config_lock(MEX_DEF_INPUT){
    //27
}

void config_lookup_map_value(MEX_DEF_INPUT){
    //28
}

void config_multivar_iterator_new(MEX_DEF_INPUT){
    //29
}

void config_new(MEX_DEF_INPUT){
    //30
}

void config_next(MEX_DEF_INPUT){
    //31
}

void config_open_default(MEX_DEF_INPUT){
    //32
}

void config_open_global(MEX_DEF_INPUT){
    //33
}

void config_open_level(MEX_DEF_INPUT){
    //34
}

void config_open_ondisk(MEX_DEF_INPUT){
    //35
}

void config_parse_bool(MEX_DEF_INPUT){
    //36
}

void config_parse_int32(MEX_DEF_INPUT){
    //37
}

void config_parse_int64(MEX_DEF_INPUT){
    //38
}

void config_parse_path(MEX_DEF_INPUT){
    //39
}

void config_set_bool(MEX_DEF_INPUT){
    //40
}

void config_set_int32(MEX_DEF_INPUT){
    //41
}

void config_set_int64(MEX_DEF_INPUT){
    //42
}

void config_set_multivar(MEX_DEF_INPUT){
    //43
}

void config_set_string(MEX_DEF_INPUT){
    //44
}

void config_snapshot(MEX_DEF_INPUT){
    //45
}

void config(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //git_config_add_backend
                config_add_backend(MEX_INPUT);
            break;
        case 2:
            //git_config_add_file_ondisk
            config_add_file_ondisk(MEX_INPUT);
            break;
        case 3:
            //git_config_backend_foreach_match
            config_backend_foreach_match(MEX_INPUT);
            break;
        case 4:
            //git_config_delete_entry
            config_delete_entry(MEX_INPUT);
            break;
        case 5:
            //git_config_delete_multivar
            config_delete_multivar(MEX_INPUT);
            break;
        case 6:
            //git_config_entry_free
            config_entry_free(MEX_INPUT);
            break;
        case 7:
            //git_config_find_global
            config_find_global(MEX_INPUT);
            break;
        case 8:
            //git_config_find_programdata
            config_find_programdata(MEX_INPUT);
            break;
        case 9:
            //git_config_find_system
            config_find_system(MEX_INPUT);
            break;
        case 10:
            //git_config_find_xdg
            config_find_xdg(MEX_INPUT);
            break;
        case 11:
            //git_config_foreach
            config_foreach(MEX_INPUT);
            break;
        case 12:
            //git_config_foreach_match
            config_foreach_match(MEX_INPUT);
            break;
        case 13:
            //git_config_free
            config_free(MEX_INPUT);
            break;
        case 14:
            //git_config_get_bool
            config_get_bool(MEX_INPUT);
            break;
        case 15:
            //git_config_get_entry
            config_get_entry(MEX_INPUT);
            break;
        case 16:
            //git_config_get_int32
            config_get_int32(MEX_INPUT);
            break;
        case 17:
            //git_config_get_int64
            config_get_int64(MEX_INPUT);
            break;
        case 18:
            //git_config_get_mapped
            config_get_mapped(MEX_INPUT);
            break;
        case 19:
            //git_config_get_multivar_foreach
            config_get_multivar_foreach(MEX_INPUT);
            break;
        case 20:
            //git_config_get_path
            config_get_path(MEX_INPUT);
            break;
        case 21:
            //git_config_get_string
            config_get_string(MEX_INPUT);
            break;
        case 22:
            //git_config_get_string_buf
            config_get_string_buf(MEX_INPUT);
            break;
        case 23:
            //git_config_init_backend
            config_init_backend(MEX_INPUT);
            break;
        case 24:
            //git_config_iterator_free
            config_iterator_free(MEX_INPUT);
            break;
        case 25:
            //git_config_iterator_glob_new
            config_iterator_glob_new(MEX_INPUT);
            break;
        case 26:
            //git_config_iterator_new
            config_iterator_new(MEX_INPUT);
            break;
        case 27:
            //git_config_lock
            config_lock(MEX_INPUT);
            break;
        case 28:
            //git_config_lookup_map_value
            config_lookup_map_value(MEX_INPUT);
            break;
        case 29:
            //git_config_multivar_iterator_new
            config_multivar_iterator_new(MEX_INPUT);
            break;
        case 30:  
            //git_config_new
            config_new(MEX_INPUT);
            break;
        case 31:
            //git_config_next
            config_next(MEX_INPUT);
            break;
        case 32:
            //git_config_open_default
            config_open_default(MEX_INPUT);
            break;
        case 33:
            //git_config_open_global
            config_open_global(MEX_INPUT);
            break;
        case 34:
            //git_config_open_level
            config_open_level(MEX_INPUT);
            break;
        case 35:
            //git_config_open_ondisk
            config_open_ondisk(MEX_INPUT);
            break;
        case 36:
            //git_config_parse_bool
            (MEX_INPUT);
            break;
        case 37:
            //git_config_parse_int32
            config_parse_int32(MEX_INPUT);
            break;
        case 38:
            //git_config_parse_int64
            config_parse_int64(MEX_INPUT);
            break;
        case 39:
            //git_config_parse_path
            config_parse_path(MEX_INPUT);
            break;
        case 40:
            //git_config_set_bool
            config_set_bool(MEX_INPUT);
            break;
        case 41:
            //git_config_set_int32
            config_set_int32(MEX_INPUT);
            break;
        case 42:
            //git_config_set_int64
            config_set_int64(MEX_INPUT);
            break;
        case 43:
            //git_config_set_multivar
            config_set_multivar(MEX_INPUT);
            break;
        case 44:
            //git_config_set_string
            config_set_string(MEX_INPUT);
            break;
        case 45:
            //git_config_snapshot
            config_snapshot(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","config.h, input sub-type not recognized");
    }
}

//01 git_config_add_backend
//02 git_config_add_file_ondisk
//03 git_config_backend_foreach_match
//04 git_config_delete_entry
//05 git_config_delete_multivar
//06 git_config_entry_free
//07 git_config_find_global
//08 git_config_find_programdata
//09 git_config_find_system
//10 git_config_find_xdg
//11 git_config_foreach
//12 git_config_foreach_match
//13 git_config_free
//14 git_config_get_bool
//15 git_config_get_entry
//16 git_config_get_int32
//17 git_config_get_int64
//18 git_config_get_mapped
//19 git_config_get_multivar_foreach
//20 git_config_get_path
//21 git_config_get_string
//22 git_config_get_string_buf
//23 git_config_init_backend
//24 git_config_iterator_free
//25 git_config_iterator_glob_new
//26 git_config_iterator_new
//27 git_config_lock
//28 git_config_lookup_map_value
//29 git_config_multivar_iterator_new
//30 git_config_new
//31 git_config_next
//32 git_config_open_default
//33 git_config_open_global
//34 git_config_open_level	
//35 git_config_open_ondisk
//36 git_config_parse_bool	
//37 git_config_parse_int32
//38 git_config_parse_int64
//39 git_config_parse_path
//40 git_config_set_bool
//41 git_config_set_int32
//42 git_config_set_int64	
//43 git_config_set_multivar
//44 git_config_set_string
//45 git_config_snapshot	











