--Section1

SELECT 
    name,
    CASE
        WHEN net_transfer_record LIKE '+%' AND net_transfer_record LIKE '%k' THEN 
            CAST(REPLACE(REPLACE(net_transfer_record, '+', ''), 'k', '')::FLOAT * 1000 AS INTEGER)
        WHEN net_transfer_record LIKE '+%' AND net_transfer_record LIKE '%m' THEN 
            CAST(REPLACE(REPLACE(net_transfer_record, '+', ''), 'm', '')::FLOAT * 1000000 AS INTEGER)
        WHEN net_transfer_record LIKE '-%' AND net_transfer_record LIKE '%k' THEN 
            CAST(REPLACE(net_transfer_record, 'k', '')::FLOAT * 1000 AS INTEGER)
        WHEN net_transfer_record LIKE '-%' AND net_transfer_record LIKE '%m' THEN 
            CAST(REPLACE(net_transfer_record, 'm', '')::FLOAT * 1000000 AS INTEGER)
        ELSE
            0
    END AS total
FROM clubs
ORDER BY total DESC, name ASC;