<?php

function convertJsonToTable($data)
{
    $temp = "<table border=\"3\">";
    $temp .= "<tr><th>Id</th>";
    $temp .= "<th>Title</th>";
    $temp .= "<th>Price</th>";
    $temp .= "<th>Attributes</th>";
    $temp .= "<th>Categories</th></tr>";

    for ($i=0; $i < sizeof($data["products"]); $i++) { 
        $temp .= "<tr>";
        $temp .= "<td>" . $data["products"][$i]["id"] . "</td>";
        $temp .= "<td>" . $data["products"][$i]["title"] . "</td>";
        $temp .= "<td>" . $data["products"][$i]["price"] . "</td>";
        
        $attributes_color = "";
        $attributes_size = "";
        $current_labels = array_unique($data["products"][$i]["labels"]);
        $len = sizeof($current_labels);
        if($len>0)
        {
            for ($j=0; $j < $len-1; $j++)
            { 
                $cur_id =(int) $current_labels[$j];
                if($cur_id <= 7)
                {
                    if(strlen($attributes_color) == 0)
                    {
                        $attributes_color .= $data["attributes"][0]["labels"][$cur_id - 1]["title"];   
                    }
                    else
                    {
                        $attributes_color .= "," . $data["attributes"][0]["labels"][$cur_id - 1]["title"] ;
                    }
                }
                else if($cur_id <= 13)
                {
                    if(strlen($attributes_size) == 0)
                    {
                        $attributes_size .= $data["attributes"][1]["labels"][$cur_id - 8]["title"];   
                    }
                    else
                    {
                        $attributes_size .= "," . $data["attributes"][1]["labels"][$cur_id - 8]["title"] ;
                    }
                }
                else if($cur_id <=19)
                {
                    if(strlen($attributes_size) == 0)
                    {
                        $attributes_size .= $data["attributes"][2]["labels"][$cur_id - 14]["title"];   
                    }
                    else
                    {
                        $attributes_size .= "," . $data["attributes"][2]["labels"][$cur_id - 14]["title"];
                    }
                }
            }
            $cur_id =(int) $data["products"][$i]["labels"][$len-1];
            if($cur_id <= 7)
            {
                $attributes_color .=  "," . $data["attributes"][0]["labels"][$cur_id - 1]["title"];
            }
            else if($cur_id <= 13)
            {
                $attributes_size .= "," . $data["attributes"][1]["labels"][$cur_id - 8]["title"];
            }
            else if($cur_id <=19)
            {
                $attributes_size .= "," . $data["attributes"][2]["labels"][$cur_id - 14]["title"];
            }
        }
        
        $temp .= "<td>";
        if(strlen($attributes_color)>0){
            $temp .= "Color: " . $attributes_color;
            if(strlen($attributes_size)>0){
                $temp .= "<br/>";
            }
        }
        if(strlen($attributes_size)>0){
            $temp .= "Size: " . $attributes_size;
        }
        $temp .= "</td>";
        $curr_categories = "";
        for ($j=0; $j < sizeof($data["products"][$i]["categories"]); $j++) { 
            $curr_categories .= $data["products"][$i]["categories"][$j]["title"] .= ", ";
        }
        $temp .= "<td>" . $curr_categories . "</td>";
        $temp .= "</tr>"; 
    }
    $temp .= "</table>";
    echo $temp;
}
$string = file_get_contents("catalog.json");
$data = json_decode($string, true);
convertJsonToTable($data);
?>