using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreaterScript : MonoBehaviour
{
    [SerializeField]
    private float cycle = 2;
    private float time = 0;
    [SerializeField]
    private float rate = 30;
    public GameObject obj;
    GameObject Changer;
    public int score = 0;
    public bool dirChange;

    // Start is called before the first frame update
    void Start()
    {
        Changer = GameObject.FindGameObjectWithTag("Changer");
        dirChange = false;
        time = 0;
        score = 0;
    }

    // Update is called once per frame
    void Update()
    {
        time += Time.deltaTime;
        if(time >= cycle)
        {
            createObj();
        }
    }

    void createObj()
    {
        float randfloat = Random.Range(0.0f, 1.0f);
        float instanceRate = rate / 100;
        if(randfloat <= instanceRate)
        {
            Instantiate(obj, new Vector3(0, 0, 0), Quaternion.identity);
            obj.GetComponent<objScript>().goodObj = false;
        }
        else
        {
            Instantiate(obj, new Vector3(0, 0, 0), Quaternion.identity);
            obj.GetComponent<objScript>().goodObj = true;
        }
        time = 0;
    }

    public void setdirChange()
    {
        if (dirChange == true)
        {
            dirChange = false;
            Changer.GetComponent<MeshRenderer>().material.color = Color.green;
        }
        else if (dirChange == false)
        {
            dirChange = true;
            Changer.GetComponent<MeshRenderer>().material.color = Color.red;
        }
    }
}
