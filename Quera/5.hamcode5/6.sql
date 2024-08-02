-- Section1

SELECT 
	sport, 
	COUNT(medal) AS medal_count  
FROM 
	athletes  
WHERE 
	team = 'Iran' AND 
	medal IS NOT NULL  
GROUP BY 
	sport  
ORDER BY 
	medal_count DESC  
LIMIT 3;

-- Section2

SELECT 
	name, 
	medal  
FROM 
	athletes  
WHERE 
	team = 'Iran' AND
	medal IS NOT NULL
ORDER BY   
    CASE   
        WHEN medal = 'Gold'   THEN 1  
        WHEN medal = 'Silver' THEN 2  
        WHEN medal = 'Bronze' THEN 3  
    END,  
    name;

-- Section3

SELECT  
    c.name AS coach_name,  
    a.team,  
    SUM(CASE WHEN a.medal = 'Gold'   THEN 1 ELSE 0 END) AS gold_medal,  
    SUM(CASE WHEN a.medal = 'Silver' THEN 1 ELSE 0 END) AS silver_medal,  
    SUM(CASE WHEN a.medal = 'Bronze' THEN 1 ELSE 0 END) AS bronze_medal,  
    SUM(CASE   
            WHEN a.medal = 'Gold'   THEN 25   
            WHEN a.medal = 'Silver' THEN 20   
            WHEN a.medal = 'Bronze' THEN 15   
            ELSE 0   
        END) AS total_point  
FROM  
    coaches AS c  
    JOIN 
		athletes AS a 
			ON c.athlete_id = a.id   
WHERE   
    a.sport = 'Wrestling' AND
    a.sex = 'M'  
GROUP BY   
    c.name, 
    a.team  
ORDER BY   
    total_point DESC,   
    coach_name ASC  
LIMIT 10;

-- Section4

SELECT   
    team,  
    COUNT(CASE WHEN sex = 'F' AND medal IS NOT NULL THEN 1 END) AS female_medalists,  
    COUNT(CASE WHEN sex = 'M' AND medal IS NOT NULL THEN 1 END) AS male_medalists,  
    ROUND(  
        COUNT(CASE WHEN sex = 'F' AND medal IS NOT NULL THEN 1 END) * 1.0 /   
        NULLIF(COUNT(CASE WHEN sex = 'M' AND medal IS NOT NULL THEN 1 END), 0),   
        2  
    ) AS female_to_male_ratio  
FROM   
    athletes  
GROUP BY   
    team  
HAVING   
    COUNT(CASE WHEN sex = 'F' AND medal IS NOT NULL THEN 1 END) >= 7  
ORDER BY   
    female_medalists DESC,   
    female_to_male_ratio DESC  
LIMIT 22;