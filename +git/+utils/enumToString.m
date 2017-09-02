function str = enumToString(class_name,value)
%
%   str = git.utils.enumToString(class_name,value)

mc = meta.class.fromName(class_name);
mprop = mc.PropertyList;
values = [mprop.DefaultValue];

I = find(values == value);

%TODO: verify single match
%TODO: verify no empty properties (length matches after concatenation)

str = mprop(I).Name;


end