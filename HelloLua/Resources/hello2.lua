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