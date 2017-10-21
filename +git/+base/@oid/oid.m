classdef oid
    %
    %   Class:
    %   git.base.oid
    %
    %   See Also
    %   --------
    
    properties (Hidden)
        h
    end
    
    properties (Dependent)
        raw
        hex
    end
    
    methods
        function value = get.raw(obj)
            value = obj.h;
        end
    end
    
    methods
        function obj = oid(oid_raw)
            %
            %   obj = git.base.oid(oid_raw)
            %
            
            %   Created in reference
            %
            %Where else can we get this from???
            
%             git_annotated_commit_id, 
%             git_blob_id, 
%             git_commit_id, 
%             git_commit_parent_id, 
%             git_commit_tree_id, 
%             git_filter_source_id, 
%             git_index_checksum, 
%             git_indexer_hash, 
%             git_note_id, 
%             git_object_id, 
%             git_odb_object_id, 
%             git_oid_shorten_new, 
%             git_packbuilder_hash, 
%             git_reference_target, 
%             git_reference_target_peel, 
%             git_reflog_entry_id_new, 
%             git_reflog_entry_id_old, 
%             git_submodule_head_id, 
%             git_submodule_index_id, 
%             git_submodule_wd_id, 
%             git_tag_id, 
%             git_tag_target_id, 
%             git_tree_entry_id, 
%             git_tree_id.
            
            
            %git_reference_name_to_id => repo,ref_name
            obj.h = oid_raw;
            
            
            
        end
    end
    
end

%git_oid_cmp
%git_oid_cpy
%git_oid_equal
%git_oid_fmt - Format a git_oid into a hex string.
%git_oid_fromraw - Copy an already raw oid into a git_oid structure.
%git_oid_fromstr - Parse a hex formatted object id into a git_oid.
%git_oid_fromstrn - Parse N characters of a hex formatted object id into a git_oid.
%git_oid_fromstrp - Parse a hex formatted null-terminated string into a git_oid.
%git_oid_iszero - Check is an oid is all zeros.
%git_oid_ncmp
%git_oid_nfmt
%git_oid_pathfmt - Format a git_oid into a loose-object path string.

%GIT shortener
%-------------------
%git_oid_shorten_add
%git_oid_shorten_free
%git_oid_shorten_new

%git_oid_strcmp
%git_oid_streq
%git_oid_tostr - Format a git_oid into a buffer as a hex format c-string.
%git_oid_tostr_s - Format a git_oid into a statically allocated c-string.