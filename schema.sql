Table USERS {
  id integer [primary key]
  login varchar
  role varchar
}

Table WORKSHOPS {
  workshop_id integer [primary key]
  address varchar
}

Table MECHANICS {
  mechanic_id integer [primary key]
  workshop_id integer
}

Table CARS {
  plate_number varchar [primary key]
  owner_name varchar
}

Table REPAIRS {
  repair_id integer [primary key]
  workshop_id integer
  mechanic_id integer
  plate_number varchar
}

Ref: WORKSHOPS.workshop_id < MECHANICS.workshop_id
Ref: WORKSHOPS.workshop_id < REPAIRS.workshop_id
Ref: MECHANICS.mechanic_id < REPAIRS.mechanic_id
Ref: CARS.plate_number < REPAIRS.plate_number