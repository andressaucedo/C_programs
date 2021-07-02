
#!/bin/bash

output=""
for i in 0 1
do
	LEVEL=$(cat /sys/class/power_supply/BAT$i/capacity)
	STATUS=$(cat /sys/class/power_supply/BAT$i/status | cut -c1-3)
	if [ "$STATUS" == "Unk" ]; then
		STATUS=""
	fi
	if [ ${#output} -eq 0 ]; then
		output=" Batt $i: $LEVEL% $STATUS"
	else
		output="$output | Batt $i: $LEVEL% $STATUS"
	fi
done
echo $output
