<?php
class Category{
    public $counter;
    public $name;
    public $related_products;

    //Methods
    function __construct($name)
    {
        $this->counter = 0;
        $this->name = $name;
        $this->related_products = array();
    }
    function addProducts($product)
    {
        $this->related_products[$this->counter] = $product;
        $this->counter += 1;
    }
    function getName(){
        return $this->name;
    }
    function getProducts()
    {
        return $this->related_products;
    }
}

function getCategories($data)
{
    $data_by_categories = array();
    for ($i=0; $i < sizeof($data["products"]); $i++)
    {
        for ($j=0; $j < sizeof($data["products"][$i]["categories"]); $j++) {
            $cur_name =  $data["products"][$i]["categories"][$j]["title"];
            if(array_key_exists($cur_name, $data_by_categories)==FALSE)
            {
                $data_by_categories[$cur_name] = new Category($cur_name);
            }
            $data_by_categories[$cur_name]->addProducts($data["products"][$i]["id"]);
        }
    }
    // foreach ($data_by_categories as $value) {
    //     echo $value->getName(), '<br>';
    //     for ($i=0; $i < sizeof($value->getProducts()); $i++) { 
    //         echo $value->getProducts()[$i], '<br>';
    //     }
    //     echo '<br>';
    // }
    return $data_by_categories;
}
function dataToTable($data_by_categories, $data)
{
    foreach ($data_by_categories as $value) {
        echo "Category: " . $value->getName(), '<br>';
        $temp = "<table border=\"3\">";
        $temp .= "<tr><th>Id</th>";
        $temp .= "<th>Title</th>";
        $temp .= "<th>Price</th>";
        $curr_products = $value->getProducts();
        for ($i=0; $i < sizeof($curr_products); $i++) { 
            $temp .= "<tr>";
            $temp .= "<td>" . $data["products"][$curr_products[$i]-1]["id"] . "</td>";
            $temp .= "<td>" . $data["products"][$curr_products[$i]-1]["title"] . "</td>";
            $temp .= "<td>" . $data["products"][$curr_products[$i]-1]["price"] . "</td>";
            $temp .= "</tr>"; 
        }
        $temp .= "</table>";
        $temp .= "<br>";
        echo $temp;
    }
}
$string = file_get_contents("catalog.json");
$data = json_decode($string, true);
$data_by_categories = getCategories($data);
dataToTable($data_by_categories, $data);
?>