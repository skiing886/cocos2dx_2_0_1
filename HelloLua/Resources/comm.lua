--Create an class from cocos2dx.
function class(classname, super)
	local superType = type(super);
	local cls;
	if superType ~= "function" and superType ~= "table" then
		   superType = nil
		   super = nil
	end
	if superType == "function" or (super and super.__ctype == 1) then
		-- inherited from native C++ Object
		cls = {}
		if superType == "table" then
		-- copy fields from super
			for k,v in pairs(super) do cls[k] = v end
			cls.__create = super.__create
			cls.super    = super
		else
			cls.__create = super
		end
		cls.ctor    = function() end -- dot not implement ctor-function yet
		cls.__cname = classname
		cls.__ctype = 1 -- c++ 
		--implement the new function
		print("super type is " .. type(super));
		function cls.new(...)
			local instance = cls.__create(...) --we just call the create-function from base-class
			-- copy fields from class to native object
			for k,v in pairs(cls) do instance[k] = v end
			instance.class = cls
			instance:ctor(...)
			return instance
		end
	else
		-- inherited from Lua Object
		if super then
			cls = clone(super)
			cls.super = super
		else
			cls = {ctor = function() end}
		end
		cls.__cname = classname
		cls.__ctype = 2 -- lua
		cls.__index = cls
		function cls.new(...)
			local instance = setmetatable({}, cls)
			instance.class = cls
			instance:ctor(...)
			return instance
		end
	end
	return cls
end

--[[
there is a example
MySprite = class("MySprite",
			function(szFileName)
				return CCSprite:create(szFileName);
			end
);
MySprite.__index = MySprite;
MySprite.type = 0;

function MySprite:createMS(szFileName, _type)
	local mySprite = MySprite.new(szFileName);	
	mySprite:myInit(_type);
	return mySprite;		
end
function MySprite:myInit(_type)
	self.type = _type;
end

local sp = MySprite:createMS("dog.png", 1);--native c++ object
sp:setPosition(100, 100);
sceneGame:addChild(sp);
--]]

function schedule(node, callback, delay)
	local delay = CCDelayTime:create(delay)
	local callfunc = CCCallFunc:create(callback)
	local sequence = CCSequence:createWithTwoActions(delay, callfunc)
	local action = CCRepeatForever:create(sequence)
	node:runAction(action)
	return action
end

function performWithDelay(node, callback, delay)
	local delay = CCDelayTime:create(delay)
	local callfunc = CCCallFunc:create(callback)
	local sequence = CCSequence:createWithTwoActions(delay, callfunc)
	node:runAction(sequence)
	return sequence
end




--以下是云风实现的oop版本
local _class={}
function class_ex(super)
	local class_type={}
	class_type.ctor=false
	class_type.super=super
	class_type.new=function(...) 
			local obj={}
			do
				local create
				create = function(c,...)
					if c.super then
						create(c.super,...)
					end
					if c.ctor then
						c.ctor(obj,...)
					end
				end
 
				create(class_type,...)
			end
			setmetatable(obj,{ __index=_class[class_type] })
			return obj
		end
	local vtbl={}
	_class[class_type]=vtbl
 
	setmetatable(class_type,{__newindex=
		function(t,k,v)
			vtbl[k]=v
		end
	})
 
	if super then
		setmetatable(vtbl,{__index=
			function(t,k)
				local ret=_class[super][k]
				vtbl[k]=ret
				return ret
			end
		})
	end
 
	return class_type
end

--common function 
function myadd(x, y)
    return x + y
end

function get_msg(n, o)
	function _my_print(o)
		if type(o) == "number" then
			msg = msg .. o;
		elseif type(o) == "string" then
			msg = msg .. string.format("%q", o);
		elseif type(o) == "table" then
			msg = msg .. "\n{\n";
			for k,v in pairs(o) do
				msg = msg .. " [";
				_my_print(k);
				msg = msg .. "] = ";
				_my_print(v);
				msg = msg .. ",\n";
			end
			msg = msg .. "}\n";
		elseif type(o) == "function" then
			msg = msg .. tostring(o);
		else
			error("cannot serialize a " .. type(o));
		end
	end
	if (o) then
		msg = n .. " = ";
	else
		o = n;
		msg = "";
	end
	_my_print(o);
	return msg;
end

function print_lua_table (lua_table, indent)
	indent = indent or 0
	for k, v in pairs(lua_table) do
		if type(k) == "string" then
			k = string.format("%q", k)
		end
		local szSuffix = ""
		if type(v) == "table" then
			szSuffix = "\n{"
		end
		local szPrefix = string.rep("    ", indent)
		formatting = szPrefix.."["..k.."]".." = "..szSuffix
		if type(v) == "table" then
			print(formatting)
			print_lua_table(v, indent + 1)
			print(szPrefix.."},")
		else
			local szValue = ""
			if type(v) == "string" then
				szValue = string.format("%q", v)
			else
				szValue = tostring(v)
			end
			print(formatting..szValue..",")
		end
	end
end

--
function maxindex(arr)
  local index = 1;
  local max = arr[index];
  for i,v in ipairs(arr) do
    if(v > max) then
      index = i;
      max = v;
     end;
  end
  return max,index;
end;

--返回数组的所有元素
--@param t：目标表
--@param i：索引
--返回：表t的所有元素
function my_unpack(t, i)
	i = i or 1;
	if t[i] then
		return t[i],my_unpack(t, i+1);
	end
end

function select(n, ...)
	return arg[n];
end

function echo(t,n,saved)
	saved = saved or {}
	n = n or 0
	for k in pairs(t) do
	   local str = ''
	   if n~=0 then
		local fmt = '%' .. 2*n .. 's'
		str = string.format(fmt, '')
	   end
	   io.write(str,tostring(k), ' = ')
	   if type(t[k])=='table' then
		local m = n
		m = m+1
		if saved[t[k]] then
		 io.write(saved[t[k]], '\n')
		else
		 saved[t[k]] = k
		 io.write('{\n')
		 echo(t[k], m, saved)
		 io.write(str,'}\n')
		end
	   else
		io.write(tostring(t[k]),'\n')
	   end
	end
end