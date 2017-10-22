classdef options
    %
    %   Class:
    %   git.base.libgit.options
    
    properties (Dependent)
        max_mmap_window_size
        max_memory_library
        n_bytes_in_cache
        max_bytes_in_cache
        
        %TODO: I'm getting 8 GB for n_bytes_in_cache and 1 for max_bytes_in_cache
        %
        %   What does this mean?
    end
    
    methods
        function value = get.max_mmap_window_size(obj)
            value = libgit(4,1,1);
        end
%         function set.max_mmap_window_size(obj,value)
%         end
        function value = get.max_memory_library(obj)
            value = libgit(4,1,2);
        end
        function value = get.n_bytes_in_cache(obj)
            [value,~] = libgit(4,1,4);
        end
        function value = get.max_bytes_in_cache(obj)
            [~,value] = libgit(4,1,4);
        end
    end
    
end

%{

 opts(GIT_OPT_GET_MWINDOW_SIZE, size_t *):

    > Get the maximum mmap window size

* opts(GIT_OPT_SET_MWINDOW_SIZE, size_t):

    > Set the maximum mmap window size

* opts(GIT_OPT_GET_MWINDOW_MAPPED_LIMIT, size_t *):

    > Get the maximum memory that will be mapped in total by the library

* opts(GIT_OPT_SET_MWINDOW_MAPPED_LIMIT, size_t):

    >Set the maximum amount of memory that can be mapped at any time        by the library

* opts(GIT_OPT_GET_SEARCH_PATH, int level, git_buf *buf)

    > Get the search path for a given level of config data.  "level" must       > be one of `GIT_CONFIG_LEVEL_SYSTEM`, `GIT_CONFIG_LEVEL_GLOBAL`,       > `GIT_CONFIG_LEVEL_XDG`, or `GIT_CONFIG_LEVEL_PROGRAMDATA`.        > The search path is written to the `out` buffer.

* opts(GIT_OPT_SET_SEARCH_PATH, int level, const char *path)

    > Set the search path for a level of config data.  The search path      > applied to shared attributes and ignore files, too.       >       > - `path` lists directories delimited by GIT_PATH_LIST_SEPARATOR.      >   Pass NULL to reset to the default (generally based on environment       >   variables).  Use magic path `$PATH` to include the old value        >   of the path (if you want to prepend or append, for instance).       >       > - `level` must be `GIT_CONFIG_LEVEL_SYSTEM`,      >   `GIT_CONFIG_LEVEL_GLOBAL`, `GIT_CONFIG_LEVEL_XDG`, or       >   `GIT_CONFIG_LEVEL_PROGRAMDATA`.

* opts(GIT_OPT_SET_CACHE_OBJECT_LIMIT, git_otype type, size_t size)

    > Set the maximum data size for the given type of object to be      > considered eligible for caching in memory.  Setting to value to       > zero means that that type of object will not be cached.       > Defaults to 0 for GIT_OBJ_BLOB (i.e. won't cache blobs) and 4k        > for GIT_OBJ_COMMIT, GIT_OBJ_TREE, and GIT_OBJ_TAG.

* opts(GIT_OPT_SET_CACHE_MAX_SIZE, ssize_t max_storage_bytes)

    > Set the maximum total data size that will be cached in memory     > across all repositories before libgit2 starts evicting objects        > from the cache.  This is a soft limit, in that the library might      > briefly exceed it, but will start aggressively evicting objects       > from cache when that happens.  The default cache size is 256MB.

* opts(GIT_OPT_ENABLE_CACHING, int enabled)

    > Enable or disable caching completely.     >       > Because caches are repository-specific, disabling the cache       > cannot immediately clear all cached objects, but each cache will      > be cleared on the next attempt to update anything in it.

* opts(GIT_OPT_GET_CACHED_MEMORY, ssize_t *current, ssize_t *allowed)

    > Get the current bytes in cache and the maximum that would be      > allowed in the cache.

* opts(GIT_OPT_GET_TEMPLATE_PATH, git_buf *out)

    > Get the default template path.        > The path is written to the `out` buffer.

* opts(GIT_OPT_SET_TEMPLATE_PATH, const char *path)

    > Set the default template path.        >       > - `path` directory of template.

* opts(GIT_OPT_SET_SSL_CERT_LOCATIONS, const char *file, const char *path)

    > Set the SSL certificate-authority locations.      >       > - `file` is the location of a file containing several     >   certificates concatenated together.     > - `path` is the location of a directory holding several       >   certificates, one per file.     >       > Either parameter may be `NULL`, but not both.

* opts(GIT_OPT_SET_USER_AGENT, const char *user_agent)

    > Set the value of the User-Agent header.  This value will be       > appended to "git/1.0", for compatibility with other git clients.      >       > - `user_agent` is the value that will be delivered as the     >   User-Agent header on HTTP requests.

* opts(GIT_OPT_ENABLE_STRICT_OBJECT_CREATION, int enabled)

    > Enable strict input validation when creating new objects      > to ensure that all inputs to the new objects are valid.  For      > example, when this is enabled, the parent(s) and tree inputs      > will be validated when creating a new commit.  This defaults      > to enabled.

* opts(GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION, int enabled)

    > Validate the target of a symbolic ref when creating it.  For      > example, `foobar` is not a valid ref, therefore `foobar` is       > not a valid target for a symbolic ref by default, whereas     > `refs/heads/foobar` is.  Disabling this bypasses validation       > so that an arbitrary strings such as `foobar` can be used     > for a symbolic ref target.  This defaults to enabled.

* opts(GIT_OPT_SET_SSL_CIPHERS, const char *ciphers)

    > Set the SSL ciphers use for HTTPS connections.        >       > - `ciphers` is the list of ciphers that are eanbled.
signature

int git_libgit2_opts(int option);
versions

%}