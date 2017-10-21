classdef revwalk
    %
    %   Class:
    %   git.base.revwalk
    %
    %   See Also
    %   --------
    %   git.base.repository
    
    
% // git_revwalk *walker;
% // git_revwalk_new(&walker, repo);
% // git_revwalk_push_ref(walker, "refs/remotes/origin/master");
% // git_revwalk_hide_ref(walker, "refs/heads/master");
% // 
% // git_oid id;
% // int count = 0;
% // while (!git_revwalk_next(&id, walker))
% //     ++count;


%push - root
%hide - stop point

    %{
        repo = git.base.repository(file_path);

        remote = repo.getRemote('origin');
        remote.fetch
        remote.fetch('refs/heads/master');

        ref1 = repo.getReference('refs/remotes/origin/master');
        ref2 = repo.getReference('refs/heads/master');
        id1 = ref1.oid;
        id2 = ref2.oid;

        %How many ahead is the remote
        walk = repo.getRevWalker();
        walk.pushRef('refs/remotes/origin/master');
        walk.hideRef('refs/heads/master');

        %How many ahead is the local copy?
        walk.hideRef('refs/remotes/origin/master');
        walk.pushRef('refs/heads/master');

        
        %Test
        walk.pushRef('refs/remotes/origin/no_exist')


    %}
    
    properties (Hidden)
        h
    end
    
    methods (Static)
        function walk = fromRepo(repo)
            %
            %   walk = git.base.revwalk.fromRepo(repo)
            
            h = libgit(52,7,repo.h);
            walk = git.base.revwalk(h);
        end
    end
    
    methods
        function obj = revwalk(h)
            %   
            %   obj = git.base.revwalk(h)
            
            obj.h = h;
        end
        function output = next(obj)
            %
            %
            %   next(obj)
            %
            %   When does this stop????
            
            commit_oid_raw = libgit(52,8,obj.h);
            if isempty(commit_oid_raw)
                output = [];
            else
                output = git.base.oid(commit_oid_raw);
            end
            %This may be empty
            %temp is of type
        end
        function hideRef(obj,ref_name)
            %
            %   hideRef(obj,ref_name)
            
            libgit(52,6,obj.h,ref_name)
        end
        function pushID(obj,commit_oid)
            %x Add a new root for the traversal
            %
            %   pushID(obj,commit_oid)
            %
            %   Do we want to log this?
            
            libgit(52,9,obj.h,commit_oid)
        end
        function pushHead(obj)
            %x Push the repository's HEAD
            %
            %   pushHead(obj)
            
            libgit(52,11,obj.h)
        end
        function pushGlob(obj,glob_string)
            %
            %
            %   pushGlob(obj,glob_string)
            
            libgit(52,10,obj.h,glob_string)
        end
        function pushRef(obj,ref_name)
            %
            %   pushRef(obj,ref_name)
            
            %-1 => ref_name doesn't exist
            
            libgit(52,13,obj.h,ref_name)
            
        end
        function reset(obj)
            libgit(52,15,obj.h);
        end
    end
end

% //1  git_revwalk_add_hide_cb
% //2  X  git_revwalk_free
% //3  git_revwalk_hide
% //4  git_revwalk_hide_glob
% //5  git_revwalk_hide_head
% //6  X git_revwalk_hide_ref
% //7  X  git_revwalk_new
% //8  git_revwalk_next
% //9  git_revwalk_push
% //10 X  git_revwalk_push_glob
% //11 X  git_revwalk_push_head
% //12 git_revwalk_push_range
% //13 X git_revwalk_push_ref
% //14 git_revwalk_repository
% //15 X git_revwalk_reset
% //16 git_revwalk_simplify_first_parent
% //17 git_revwalk_sorting

